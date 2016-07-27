// Temporary until the NDK build system can deal with there being no Java source.
package com.thegamecreators.agk_player;

import com.google.android.gms.ads.*;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.common.api.ResultCallback;
import com.google.android.gms.games.Games;
import com.google.android.gms.games.achievement.Achievement;
import com.google.android.gms.games.achievement.AchievementBuffer;
import com.google.android.gms.games.achievement.Achievements;
import com.google.android.gms.games.achievement.Achievements.LoadAchievementsResult;
import com.google.android.gms.plus.Plus;
import com.google.android.gms.location.LocationRequest;
import com.google.android.gms.location.LocationListener;
import com.google.android.gms.location.LocationServices;

import android.app.AlarmManager;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.SharedPreferences;
import android.location.Location;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.content.IntentSender;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.Runnable;
import java.lang.String;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.Locale;

import android.text.Editable;
import android.text.TextWatcher;
import android.text.format.Formatter;
import android.util.DisplayMetrics;
import android.util.Log;
import android.provider.MediaStore;
import android.provider.Settings.Secure;
import android.os.Bundle;
import android.os.Looper;

import com.thegamecreators.agk_player.iap.*;

import com.facebook.*;
import com.facebook.android.DialogError;
import com.facebook.android.Facebook;
import com.facebook.android.Facebook.DialogListener;
import com.facebook.android.FacebookError;
import com.google.android.gcm.GCMRegistrar;

import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.TextView;
import android.view.InputDevice;
import android.view.KeyEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;
import android.graphics.Bitmap;
import android.graphics.PixelFormat;
import android.view.Gravity;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.res.AssetFileDescriptor;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.media.MediaPlayer;
import android.media.MediaScannerConnection;
import android.content.DialogInterface;

import android.media.MediaMetadataRetriever;

import com.chartboost.sdk.*; 
import com.chartboost.sdk.Model.CBError.CBImpressionError;

import com.amazon.device.ads.*;

import com.mycompany.mytemplate.R;

// Used for agk::Message()
class RunnableMessage implements Runnable
{
	public Activity act;
	public String msg;
	
	public void run() {
        //Toast.makeText(act, msg, Toast.LENGTH_LONG).show();
		AlertDialog alertDialog;
		alertDialog = new AlertDialog.Builder(act).create();
		alertDialog.setTitle("Message");
		alertDialog.setMessage(msg);
		alertDialog.setButton( DialogInterface.BUTTON_POSITIVE, "OK", new DialogInterface.OnClickListener(){public void onClick(DialogInterface dialog, int which) {}});
		alertDialog.show();
    }
}

class MyTextWatcher implements TextWatcher
{
	public static MyTextWatcher m_TextWatcher = null;
	
	@Override
	public void afterTextChanged( Editable s )
	{
		//Log.e("EditText", AGKHelper.mTextInput.getText().toString());
	}

	@Override
	public void beforeTextChanged(CharSequence arg0, int arg1, int arg2, int arg3) {}

	@Override
	public void onTextChanged(CharSequence arg0, int arg1, int arg2, int arg3) {}
}

class MyTextActionWatcher implements TextView.OnEditorActionListener
{
	public static MyTextActionWatcher m_TextActionWatcher = null;
	public static Activity act = null;

	@Override
	public boolean onEditorAction(TextView arg0, int arg1, KeyEvent arg2) {
		//String out = String.format("Action: %d, Event: %s", arg1, arg2 == null ? "" : arg2.toString());
		//Log.e("TextView",out);
		AGKHelper.mTextFinished = true;
		return true;
	}
}

class RunnableKeyboard implements Runnable
{
	public Activity act;
	public int action = 0;
	public String text = "";
	public int multiline = 0;
	public int cursorpos = 0;
	
	public void run() {
		switch( action )
		{
			case 1: // start text input
			{
				AGKHelper.mTextInput = new EditText(act);
				AGKHelper.mTextInput.setSingleLine(multiline == 0);
				if ( MyTextWatcher.m_TextWatcher == null ) MyTextWatcher.m_TextWatcher = new MyTextWatcher();
				if ( MyTextActionWatcher.m_TextActionWatcher == null ) MyTextActionWatcher.m_TextActionWatcher = new MyTextActionWatcher();
				MyTextActionWatcher.act = act;
				
				FrameLayout.LayoutParams mEditTextLayoutParams = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT);
				mEditTextLayoutParams.gravity = Gravity.TOP;
				mEditTextLayoutParams.setMargins(0, 0, 0, 0);
				AGKHelper.mTextInput.setLayoutParams(mEditTextLayoutParams);
				AGKHelper.mTextInput.setVisibility(View.VISIBLE);
				AGKHelper.mTextInput.addTextChangedListener(MyTextWatcher.m_TextWatcher);
				AGKHelper.mTextInput.setOnEditorActionListener(MyTextActionWatcher.m_TextActionWatcher);
				
				act.addContentView(AGKHelper.mTextInput, mEditTextLayoutParams);
					
				AGKHelper.mTextInput.bringToFront();
				if ( cursorpos >= 0 ) AGKHelper.mTextInput.setSelection(cursorpos);
				AGKHelper.mTextInput.requestFocus();
				
				AGKHelper.mTextFinished = false;
				
				InputMethodManager m = (InputMethodManager) act.getSystemService(Context.INPUT_METHOD_SERVICE);
				m.showSoftInput(AGKHelper.mTextInput, 0);
				break;
			}
			case 2: // stop text input
			{
				InputMethodManager lInputMethodManager = (InputMethodManager)act.getSystemService(Context.INPUT_METHOD_SERVICE);
				lInputMethodManager.hideSoftInputFromWindow( act.getWindow().getDecorView().getWindowToken(), 0 );
				
				((ViewGroup)(AGKHelper.mTextInput.getParent())).removeView(AGKHelper.mTextInput);
				AGKHelper.mTextInput = null;
				AGKHelper.mTextHiding = false;
				break;
			}
			case 3: // position text cursor
			{
				if ( AGKHelper.mTextInput != null ) 
				{
					AGKHelper.mTextInput.setText(text);
					if ( cursorpos >= 0 ) AGKHelper.mTextInput.setSelection(cursorpos);
				}
				break;
			}
			case 4: // show keyboard for existing text input
			{
				if ( AGKHelper.mTextInput != null ) 
				{
					AGKHelper.mTextFinished = false;
					if ( cursorpos >= 0 ) AGKHelper.mTextInput.setSelection(cursorpos);
					AGKHelper.mTextInput.requestFocus();
					InputMethodManager lInputMethodManager = (InputMethodManager)act.getSystemService(Context.INPUT_METHOD_SERVICE);
					lInputMethodManager.showSoftInput( AGKHelper.mTextInput, 0 );
				}
				break;
			}
		}
    }
}

class RunnableChartboost implements Runnable
{
	public Activity act;
	public int action = 0;
	public static int caching = 0;
	public static int cached = 0;
	public static int display = 0;
	public static String AppID;
	public static String AppSig;

	private ChartboostDelegate chartBoostDelegate = new ChartboostDelegate() {
		@Override
		public boolean shouldDisplayInterstitial(String location) {
			return true;
		}

		@Override
		public boolean shouldRequestInterstitial(String location) {
			return true;
		}

		@Override
		public void didCacheInterstitial(String location) {
			Log.i("Chartboost", "INTERSTITIAL '"+(location != null ? location : "null")+"' CACHED");
			caching = 0;
			cached = 1;
			/*
            if ( display == 1 )
			{
				Chartboost.showInterstitial(CBLocation.LOCATION_DEFAULT);
				cached = 0;
				display = 0;
			}
			*/
		}

		@Override
		public void didFailToLoadInterstitial(String location, CBImpressionError error) {
			caching = 0;
			cached = 0;
			display = 0;
			Log.e("Chartboost Activity", "DID FAIL TO LOAD INTERSTITIAL '"+ (location != null ? location : "null")+ " Error: " + error.name());
		}

		@Override
		public void didDismissInterstitial(String location) {
			Log.i("Chartboost", "INSTERSTITIAL '"+(location != null ? location : "null")+"' DISMISSED");
			display = 0;
			if ( cached == 0 && caching == 0 )
			{
				Chartboost.cacheInterstitial(CBLocation.LOCATION_DEFAULT);
				caching = 1;
			}
		}

		@Override
		public void didCloseInterstitial(String location) {
			Log.i("Chartboost", "INSTERSTITIAL '"+(location != null ? location : "null")+"' CLOSED");
			display = 0;
			if ( cached == 0 && caching == 0 )
			{
				Chartboost.cacheInterstitial(CBLocation.LOCATION_DEFAULT);
				caching = 1;
			}
		}

		@Override
		public void didDisplayInterstitial(String location) {
			Log.i("Chartboost", "DID DISPLAY INTERSTITIAL: " +  (location != null ? location : "null"));
		}

		@Override
		public boolean shouldRequestMoreApps(String location) {
			return true;
		}

		@Override
		public boolean shouldDisplayMoreApps(String location) {
			return true;
		}

		@Override
		public boolean shouldDisplayRewardedVideo(String location) {
			return true;
		}
	};

	@Override
	public void run() {
		switch ( action )
		{
			case 1: // initialize
			{
				Log.i("Chartboost", "Initialize Chartboost SDK");

				cached = 0;
				caching = 1;
				display = 0;
				Chartboost.startWithAppId(this.act, AppID, AppSig);
				Chartboost.setImpressionsUseActivities(true);
				Chartboost.onCreate(this.act);
				Chartboost.setShouldRequestInterstitialsInFirstSession(true);
				Chartboost.setDelegate(this.chartBoostDelegate);
				Chartboost.onStart(this.act);
				Chartboost.cacheInterstitial(CBLocation.LOCATION_DEFAULT);
				break;
			}
			case 3: // show ad
			{
				Log.i("Chartboost", "Display Chartboost Ad");

				if ( cached == 0 )
				{
					display = 1;
					if (caching == 0)
					{
						caching = 1;
						Chartboost.cacheInterstitial(CBLocation.LOCATION_DEFAULT);
					}
				}
				else
				{
					Log.i("Chartboost", "Showing Chartboost Ad");
					cached = 0;
					Chartboost.showInterstitial( CBLocation.LOCATION_DEFAULT );
				}

				break;
			}
			case 4: // cache More Apps
			{
				//Chartboost.sharedChartboost().cacheMoreApps();
				break;
			}
			case 5: // show More Apps
			{
				//Chartboost.sharedChartboost().showMoreApps();
				break;
			}
			default:
			{
				Log.i("CBTEST", "undefinedChartboostAction");
				break;
			}
		}
	}
}

class RunnableAmazonAds implements Runnable
{
	public Activity act;
	public int action = 0;
	public static int caching = 0;
	public static int cached = 0;
	public static int display = 0;
	public static int testing = 0;
	public static String AppID;
	private static com.amazon.device.ads.InterstitialAd interstitialAd;

	private DefaultAdListener AmazonAdsDelegate = new DefaultAdListener() {
		@Override
		public void onAdLoaded(final Ad ad, final AdProperties adProperties) {
			Log.i("Amazon Ads", "Interstitial loaded");
			caching = 0;
			cached = 1;
			/*
			if ( display == 1 )
			{
				interstitialAd.showAd();
				cached = 0;
				display = 0;
			}
			*/
		}

		@Override
		public void onAdFailedToLoad(final Ad view, final AdError error) {
			caching = 0;
			cached = 0;
			display = 0;
			Log.e("Amazon Ads", "Failed to load interstitial - Error: " + error.getMessage());
		}

		@Override
		public void onAdDismissed(final Ad ad) {
			Log.i("Amazon Ads", "Interstitial dismissed");
			display = 0;
			if ( cached == 0 && caching == 0 )
			{
				caching = 1;
				interstitialAd.loadAd();
			}
		}
	};

	@Override
	public void run() {
		switch ( action )
		{
			case 1: // initialize
			{
				Log.i("Amazon Ads", "Initializing Amazon Ads SDK");

				cached = 0;
				caching = 1;
				display = 0;
				interstitialAd = new com.amazon.device.ads.InterstitialAd(act);
				AdRegistration.setAppKey(AppID);
				AdRegistration.enableTesting(false);
				interstitialAd.setListener(AmazonAdsDelegate);
				interstitialAd.loadAd();
				break;
			}
			case 2:
			{
				AdRegistration.enableTesting( testing != 0 ? true : false );
				break;
			}
			case 3: // show ad
			{
				Log.i("Amazon Ads", "Display Ad");

				if ( cached == 0 )
				{
					display = 1;
					if ( caching == 0 )
					{
						caching = 1;
						interstitialAd.loadAd();
					}
				}
				else
				{
					Log.i("Amazon Ads", "Showing Ad");
					cached = 0;
					interstitialAd.showAd();
				}

				break;
			}
			default:
			{
				Log.i("Amazon Ads", "undefined action");
				break;
			}
		}
	}
}

// Used for agk::CreateAdvert()
class RunnableAd implements Runnable
{
	public Activity act;
	public int action = 0;
	public int horz = 1;
	public int vert = 2;
	public int offsetX = 0;
	public int offsetY = 0;
	public String pubID = "";

	public static AdView ad = null;
	public static com.google.android.gms.ads.InterstitialAd interstitial = null;
	public static int displayImmediately = 0;
	public static int cached = 0;

	public WindowManager.LayoutParams makeLayout()
	{
		WindowManager.LayoutParams ll_lp;

		//Just a sample layout parameters.
		ll_lp = new WindowManager.LayoutParams();
		ll_lp.format = PixelFormat.TRANSPARENT;
		ll_lp.height = -2;
		ll_lp.width = -2;
		ll_lp.gravity = 0;
		ll_lp.x = offsetX;
		ll_lp.y = offsetY;
		switch( horz )
		{
			case 0: ll_lp.gravity |= Gravity.LEFT; break;
			case 1: ll_lp.gravity |= Gravity.CENTER_HORIZONTAL; break;
			case 2: ll_lp.gravity |= Gravity.RIGHT; break;
			default: ll_lp.gravity |= Gravity.CENTER_HORIZONTAL; break;
		}
		switch( vert )
		{
			case 0: ll_lp.gravity |= Gravity.TOP; break;
			case 1: ll_lp.gravity |= Gravity.CENTER_VERTICAL; break;
			case 2: ll_lp.gravity |= Gravity.BOTTOM; break;
			default: ll_lp.gravity |= Gravity.BOTTOM; break;
		}
		ll_lp.type = WindowManager.LayoutParams.TYPE_APPLICATION_PANEL;
		ll_lp.flags = WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL;
		ll_lp.flags = ll_lp.flags | WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;

		return ll_lp;
	}

	public void run()
	{
		switch ( action )
		{
			case 1: // make ad
			{
				if ( ad == null )
				{
					ad = new AdView(act);
					ad.setAdUnitId(pubID);
					ad.setAdSize(com.google.android.gms.ads.AdSize.BANNER);

					//request.addTestDevice("8EEA49684422A6B864134230E0A5511E");
					//request.addTestDevice("B64D549379981B01B7A5CEC68AC80EEE");

					WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
					WindowManager.LayoutParams layout = makeLayout();
					wm.addView(ad, layout);

					ad.loadAd( new AdRequest.Builder().build() );
				}
				break;
			}

			case 2: // position ad
			{
				if ( ad == null ) return;

				WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
				WindowManager.LayoutParams layout = makeLayout();
				wm.updateViewLayout(ad, layout);

				break;
			}

			case 3: // delete the ad
			{
				if ( ad == null ) return;

				WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
				wm.removeView(ad);
				ad = null;
				break;
			}

			case 4: // refresh the ad
			{
				if ( ad != null ) ad.loadAd( new AdRequest.Builder().build() );
				break;
			}

			case 5: // hide ad
			{
				if ( ad != null ) ad.setVisibility(View.GONE);
				break;
			}

			case 6: // show ad
			{
				if ( ad != null ) ad.setVisibility(View.VISIBLE);
				break;
			}

			case 7: // pause ad
			{
				if ( ad != null ) ad.pause();
				break;
			}

			case 8: // resume ad
			{
				if ( ad != null ) ad.resume();
				break;
			}

			case 9: // fullscreen ad
			{
				if ( interstitial == null )
				{
					interstitial = new com.google.android.gms.ads.InterstitialAd(act);
					interstitial.setAdUnitId(pubID);

					interstitial.setAdListener(new com.google.android.gms.ads.AdListener() {
						public void onAdLoaded() { cached = 1;/*if ( displayImmediately > 0 ) interstitial.show(); displayImmediately = 0;*/ }
						public void onAdClosed() { interstitial.loadAd(new AdRequest.Builder().build()); }
					});
				}

				if ( interstitial.isLoaded() )
				{
					cached = 0;
					interstitial.show();
				}
				else
				{
					displayImmediately = 1;
					if ( !interstitial.isLoading() )
					{
						//AdRequest adRequest = new AdRequest.Builder().addTestDevice( "B64D549379981B01B7A5CEC68AC80EEE" ).build();
						AdRequest adRequest = new AdRequest.Builder().build();
						interstitial.loadAd(adRequest);
					}
				}

				break;
			}

			case 10: // cache fullscreen ad
			{
				if ( interstitial == null )
				{
					interstitial = new com.google.android.gms.ads.InterstitialAd(act);
					interstitial.setAdUnitId(pubID);

					interstitial.setAdListener(new com.google.android.gms.ads.AdListener() {
						public void onAdLoaded() { cached = 1;/*if ( displayImmediately > 0 ) interstitial.show(); displayImmediately = 0;*/ }
						public void onAdClosed() { interstitial.loadAd(new AdRequest.Builder().build()); }
					});
				}

				if ( !interstitial.isLoaded() && !interstitial.isLoading() )
				{
					AdRequest adRequest = new AdRequest.Builder().build();
					interstitial.loadAd(adRequest);
				}

				break;
			}
		}
	}
}

class AGKSurfaceView extends SurfaceView implements SurfaceHolder.Callback, MediaPlayer.OnCompletionListener
{
	public MediaPlayer player = null;
	public Activity act;
	public SurfaceHolder pHolder = null;
	public int m_x = -10;
	public int m_y = 0;
	public int m_width = 1;
	public int m_height = 1;
	public String m_filename = "";
	public int m_filetype = 0;
	
	public int prepared = 0;
	public int isPlaying = 0;
	public int pausePos = -1;
	public int paused = 0;
	public int completed = 0;
	
	public int isDisplayed = 0;
	public int videoWidth = 0;
	public int videoHeight = 0;
	public int videoDuration = 0;
	
	public static WindowManager.LayoutParams makeLayout(int x, int y, int width, int height)
	{
		WindowManager.LayoutParams ll_lp;
		
		//Just a sample layout parameters.
		ll_lp = new WindowManager.LayoutParams();
		ll_lp.format = PixelFormat.OPAQUE;
		ll_lp.height = height;
		ll_lp.width = width; 
		ll_lp.gravity = Gravity.LEFT | Gravity.TOP;
		ll_lp.x = x;
		ll_lp.y = y;
		ll_lp.token = null;
		//ll_lp.gravity |= Gravity.CENTER_HORIZONTAL;
		//ll_lp.gravity |= Gravity.CENTER_VERTICAL;
		ll_lp.type = WindowManager.LayoutParams.TYPE_APPLICATION;
		ll_lp.flags = WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL;
		ll_lp.flags = ll_lp.flags | WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;
		ll_lp.flags = ll_lp.flags | WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE;
		
		return ll_lp;
	}
	
	public AGKSurfaceView(Activity context) 
	{
		super(context);
		
		getHolder().addCallback(this);
		getHolder().setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
		act = context;
	}
	
	public void LoadVideo( String filename, int type )
	{
		Log.i("Video", "Load Video");
		
		m_filename = filename;
		m_filetype = type;
		
		if ( player != null )
		{
			player.reset();
			player.release();
			player = null;
			
			StopVideo();
		}
		
		int m_duration = -1;
		int m_videoWidth = -1;
		int m_videoHeight = -1;
		
		MediaMetadataRetriever metaRetriever = new MediaMetadataRetriever();
		MediaPlayer tempPlayer = new MediaPlayer();
		
		Log.d("Video", "File: " + filename + " Type:" + type);
		
		try
		{
			switch( type )
			{
				case 0:
				{
					// asset folder
					AssetFileDescriptor afd = act.getAssets().openFd(filename);
					metaRetriever.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
					tempPlayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
					afd.close();
					break;
				}
				case 1:
				{
					// data folder
					metaRetriever.setDataSource(filename);
					tempPlayer.setDataSource(filename);
					break;
				}
				case 2:
				{
					/*
					// expansion file 
					int index = filename.indexOf(':');
					if ( index < 0 ) 
					{
						Log.e("Load Video","Invalid file name for expansion file");
						return;
					}
					String subfilename = filename.substring(index+1);
					ZipResourceFile expansionFile = APKExpansionSupport.getAPKExpansionZipFile( act, AGKHelper.g_iExpansionVersion, AGKHelper.g_iExpansionVersion);
					AssetFileDescriptor afd = expansionFile.getAssetFileDescriptor(subfilename);
					metaRetriever.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
					tempPlayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
					afd.close();
					break;
					*/
				}
				default:
				{
					Log.e("Video","Unrecognised file type");
					return;
				}
			}
			
			int tempprepared = 0;
			
			String duration = metaRetriever.extractMetadata(MediaMetadataRetriever.METADATA_KEY_DURATION);
			if ( duration != null ) 
			{
				m_duration = Integer.valueOf(duration); 
			}
			else
			{
				Log.w("Video", "Duration is null");
				try
				{
					tempPlayer.prepare();
					tempprepared = 1;
					m_duration = tempPlayer.getDuration();
				}
				catch( Exception e )
				{
					Log.e("Video","Temp player couldn't prepare");
				}
			}
			
			Bitmap bmp = metaRetriever.getFrameAtTime();
			if ( bmp != null )
			{
				m_videoWidth = bmp.getWidth();
				m_videoHeight = bmp.getHeight();
			}
			else 
			{
				Log.w("Video", "Bitmap is null");
				try
				{
					if ( tempprepared == 0 ) tempPlayer.prepare();
					tempprepared = 1;
					m_videoWidth = tempPlayer.getVideoWidth();
					m_videoHeight = tempPlayer.getVideoHeight();
				}
				catch( Exception e )
				{
					Log.e("Video","Temp player couldn't prepare 2");
				}
			}
			 
			Log.d("Video", "Duration: " + m_duration);
			Log.d("Video", "Width: " + Integer.toString(m_videoWidth) + " Height: " + Integer.toString(m_videoHeight));
			if ( m_videoWidth == 0 ) m_videoWidth = -1;
			if ( m_videoHeight == 0 ) m_videoHeight = -1;
		
			tempPlayer.reset();
			tempPlayer.release();
			tempPlayer = null;
		}
		catch(Exception e)
		{
			Log.e("Exception", e.toString() );
			StackTraceElement[] elements = e.getStackTrace();
			for ( int i = 0; i < elements.length; i++ )
				Log.e("Exception", elements[i].toString() );
			m_filename = "Error";
		}
		
		videoDuration = m_duration;
		videoWidth = m_videoWidth;
		videoHeight = m_videoHeight;
		pausePos = -1;
		completed = 0;
	}
	
	public void DeleteVideo()
	{
		Log.i("Video", "Delete Video");
		
		m_filename = "";
		m_filetype = 0;
		paused = 0;
		
		if ( isDisplayed == 1 )
		{
			WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
			wm.removeView(this);
			isDisplayed = 0;
		}
	}
	
	public void PlayVideo()
	{
		Log.i("Video", "Play Video");
		if ( m_filename == "" ) return;
		
		if ( player != null )
		{
			if ( pausePos >= 0 ) player.seekTo(pausePos);
			pausePos = -1;
			completed = 0;
			player.start();
		}
		
		paused = 0;
		
		if ( isDisplayed == 0 )
		{
			WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
			WindowManager.LayoutParams layout = makeLayout(m_x,m_y,m_width,m_height);
			wm.addView(this, layout);
			isDisplayed = 1;
		}
	}
	
	public void PauseVideo()
	{
		Log.i("Video", "Pause Video");
		if ( m_filename == "" ) return;
		
		paused = 1;
		if ( player == null ) return;
		if ( !player.isPlaying() ) return;
		player.pause();
	}
	
	public void StopVideo()
	{
		Log.i("Video", "Stop Video");
		paused = 0;
		
		if ( isDisplayed == 1 )
		{
			WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
			wm.removeView(this);
			isDisplayed = 0;
		}
	}
	
	public void SetDimensions( int x, int y, int width, int height )
	{
		Log.i("Video", "Set Dimensions X:" + x + " Y:" + y + " Width:" + width + " Height:" + height);
		
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		
		if ( isDisplayed == 1 && pHolder != null )
		{
			WindowManager wm = (WindowManager) act.getSystemService(Context.WINDOW_SERVICE);
			WindowManager.LayoutParams layout = makeLayout(m_x,m_y,m_width,m_height);
			wm.updateViewLayout(this, layout);
		}
	}
		
	public void surfaceCreated(SurfaceHolder holder)
	{
		Log.i("Video", "surface created");
		pHolder = holder;
		if ( player == null ) 
		{
			MediaPlayer newplayer = new MediaPlayer();
			newplayer.setOnCompletionListener(this);
			try
			{
				Log.i("Video2", "File: " + m_filename + " Type:" + m_filetype);
				
				switch( m_filetype )
				{
					case 0:
					{
						// asset folder
						AssetFileDescriptor afd = act.getAssets().openFd(m_filename);
						newplayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
						afd.close();
						break;
					}
					case 1:
					{
						// data folder
						newplayer.setDataSource(m_filename);
						break;
					}
					case 2:
					{
						/*
						// expansion file 
						int index = m_filename.indexOf(':');
						if ( index < 0 ) 
						{
							Log.e("Load Video","Invalid file name for expansion file");
							return;
						}
						String subfilename = m_filename.substring(index+1);
						ZipResourceFile expansionFile = APKExpansionSupport.getAPKExpansionZipFile( act, AGKHelper.g_iExpansionVersion, AGKHelper.g_iExpansionVersion);
						AssetFileDescriptor afd = expansionFile.getAssetFileDescriptor(subfilename);
						newplayer.setDataSource(afd.getFileDescriptor(),afd.getStartOffset(), afd.getLength());
						afd.close();
						break;
						*/
					}
					default:
					{
						Log.e("Video","Unrecognised file type");
						return;
					}
				}
			
				newplayer.setDisplay(pHolder);
				try
				{
					newplayer.prepare();
				}
				catch( Exception e )
				{
					Log.e("Prepare Exception",e.toString());
				}
				if ( pausePos >= 0 ) newplayer.seekTo(pausePos);
				pausePos = -1;
				newplayer.start();
				if ( paused == 1 ) newplayer.pause();
				
				player = newplayer;
				
				float log1=(float)(Math.log(100-AGKHelper.g_fVideoVolume)/Math.log(100));
				player.setVolume( 1-log1, 1-log1 );
			}
			catch(Exception e)
			{
				Log.e("Exception", e.toString() );
				StackTraceElement[] elements = e.getStackTrace();
				for ( int i = 0; i < elements.length; i++ )
					Log.e("Exception", elements[i].toString() );
				m_filename = "Error";
			}
		}
	}
	
	public void surfaceDestroyed(SurfaceHolder holder)
	{
		Log.i("Video", "surface destroyed");
		pHolder = null;
		
		if ( player != null )
		{
			if ( completed == 0 ) pausePos = player.getCurrentPosition();
			else pausePos = -1;
			synchronized( AGKHelper.videoLock ) 
			{
				player.reset();
				player.release();
				player = null;
			}
		}
	}
	
	public void surfaceChanged(SurfaceHolder holder, int format, int width, int height)
	{
		Log.i("Video", "Surface changed");
	}
	
	public void onCompletion(MediaPlayer mp)
	{
		Log.i("Video", "Completed");
		AGKHelper.hasStartedVideo = 0;
		completed = 1;
		StopVideo();
	}
}

class RunnableVideo implements Runnable
{
	public Activity act;
	public static AGKSurfaceView video = null;
	public int action = 0;
	
	public String filename = "";
	public int fileType = 0;
	public SurfaceHolder pHolder = null;
	public int m_x,m_y,m_width,m_height;

	public void run() 
	{
		if ( video == null ) video = new AGKSurfaceView(act);
		
		switch( action )
		{
			case 1: // Load video
			{
				video.LoadVideo(filename, fileType);
				break;
			}
			case 2: // set dimensions
			{
				video.SetDimensions(m_x, m_y, m_width, m_height);
				break;
			}
			case 3: // play
			{
				video.PlayVideo();
				break;
			}
			case 4: // stop
			{
				video.StopVideo();
				break;
			}
			case 5: // pause
			{
				video.PauseVideo();
				break;
			}
			case 6: // delete
			{
				//video.StopVideo();
				video.DeleteVideo();
				video = null;
				break;
			}
		}
	}
}

class RunnableFacebook implements Runnable
{
	String szID;
	String szLink;
	String szPicture;
	String szName;
	String szCaption;
	String szDescription;
	Activity act;
	public Session session;
	
	public void run()
	{
		Facebook feed = new Facebook(AGKHelper.appID);
		Bundle parameters = new Bundle();
	    
		if ( !szID.equals("") ) parameters.putString("to", szID);
		if ( !szLink.equals("") ) parameters.putString("link", szLink);
	    if ( !szPicture.equals("") ) parameters.putString("picture",szPicture);
	    if ( !szName.equals("") ) parameters.putString("name",szName);
	    if ( !szCaption.equals("") ) parameters.putString("caption",szCaption);
	    if ( !szDescription.equals("") ) parameters.putString("description", szDescription);
	    	    
	    feed.setSession(session);
	    
		feed.dialog(act, "feed", parameters,new DialogListener() {
	        public void onFacebookError(FacebookError arg0) { }
	        public void onError(DialogError arg0) { } 
	        public void onComplete(Bundle arg0) { }
	        public void onCancel() { }
	    });
	}
}


class AGKLocationListener implements GoogleApiClient.ConnectionCallbacks,
									 GoogleApiClient.OnConnectionFailedListener,
									 LocationListener 
{
	Activity act;

	public void onConnected(Bundle dataBundle) {
		Log.i("GPS", "Connected");
		Location mCurrentLocation;
		mCurrentLocation = LocationServices.FusedLocationApi.getLastLocation(AGKHelper.m_GPSClient);
		if ( mCurrentLocation != null )
		{
			AGKHelper.m_fGPSLatitude = (float) mCurrentLocation.getLatitude();
			AGKHelper.m_fGPSLongitude = (float) mCurrentLocation.getLongitude();
		}

		LocationRequest mLocationRequest = LocationRequest.create();
		mLocationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);
		mLocationRequest.setInterval(5000);
		mLocationRequest.setFastestInterval(1000);

		LocationServices.FusedLocationApi.requestLocationUpdates(AGKHelper.m_GPSClient, mLocationRequest, this);
	}

	public void onDisconnected() {
		Log.i("GPS", "Disconnected");
	}

	public void onConnectionFailed(ConnectionResult connectionResult) {
		/*
		 * Google Play services can resolve some errors it detects.
		 * If the error has a resolution, try sending an Intent to
		 * start a Google Play services activity that can resolve
		 * error.
		 */
		if (connectionResult.hasResolution()) {
			try {
				// Start an Activity that tries to resolve the error
				connectionResult.startResolutionForResult(act,9000);
				/*
				 * Thrown if Google Play services canceled the original
				 * PendingIntent
				 */
			} catch (IntentSender.SendIntentException e) {
				// Log the error
				e.printStackTrace();
			}
		} else {
			/*
			 * If no resolution is available, display a dialog to the
			 * user with the error.
			 */
			if ( connectionResult.getErrorCode() == ConnectionResult.SERVICE_MISSING
					|| connectionResult.getErrorCode() == ConnectionResult.SERVICE_VERSION_UPDATE_REQUIRED
					|| connectionResult.getErrorCode() == ConnectionResult.SERVICE_DISABLED )
			{
				Dialog resolution = GooglePlayServicesUtil.getErrorDialog(connectionResult.getErrorCode(), act, 9000 );
				resolution.show();
			}
			else
			{
				AGKHelper.ShowMessage(act,connectionResult.toString());
			}
		}
	}

	public void onLocationChanged(Location location) {
		AGKHelper.m_fGPSLatitude = (float) location.getLatitude();
		AGKHelper.m_fGPSLongitude = (float) location.getLongitude();
		AGKHelper.m_fGPSAltitude = (float) location.getAltitude();
		Log.i("GPS", "Updated");
	}

	@Override
	public void onConnectionSuspended(int arg0) {}
}

class AGKGameListener implements GoogleApiClient.ConnectionCallbacks,
								 GoogleApiClient.OnConnectionFailedListener, 
								 ResultCallback<Achievements.LoadAchievementsResult>
{
	Activity act;

	public void onConnected(Bundle dataBundle) 
	{
		Log.i("GameCenter","Connected");
		AGKHelper.m_GameCenterLoggedIn = 1;
		Games.Achievements.load(AGKHelper.m_GameClient, false).setResultCallback(this);
	}

	public void onDisconnected() {
		Log.i("GameCenter","Disconnected");
		AGKHelper.m_GameCenterLoggedIn = 0;
	}

	public void onConnectionFailed(ConnectionResult connectionResult) 
	{
		/*
		 * Google Play services can resolve some errors it detects.
		 * If the error has a resolution, try sending an Intent to
		 * start a Google Play services activity that can resolve
		 * error.
		 */
		if (connectionResult.hasResolution()) 
		{
			try 
			{
				AGKHelper.m_ReconnectGameCenter++;
				// Start an Activity that tries to resolve the error
				connectionResult.startResolutionForResult(act,9000);
				/*
				 * Thrown if Google Play services canceled the original
				 * PendingIntent
				 */
			} catch (IntentSender.SendIntentException e) {
				// Log the error
				e.printStackTrace();
				AGKHelper.m_GameCenterLoggedIn = -1;
				AGKHelper.ShowMessage(act,connectionResult.toString());
			}
		} 
		else 
		{
			/*
			 * If no resolution is available, display a dialog to the
			 * user with the error.
			 */
			AGKHelper.m_GameCenterLoggedIn = -1;
			if ( connectionResult.getErrorCode() == ConnectionResult.SERVICE_MISSING
					|| connectionResult.getErrorCode() == ConnectionResult.SERVICE_VERSION_UPDATE_REQUIRED
					|| connectionResult.getErrorCode() == ConnectionResult.SERVICE_DISABLED )
			{
				AGKHelper.m_ReconnectGameCenter++;
				Dialog resolution = GooglePlayServicesUtil.getErrorDialog(connectionResult.getErrorCode(), act, 9000 );
				resolution.show();
			}
			else
			{
				AGKHelper.ShowMessage(act,connectionResult.toString());
			}
		}
	}

	@Override
	public void onConnectionSuspended(int arg0) 
	{
		AGKHelper.m_GameCenterLoggedIn = 0;
		AGKHelper.m_GameClient.connect();
	}

	@Override
	public void onResult(LoadAchievementsResult arg0) {
		AGKHelper.m_AllAchievements = arg0.getAchievements();
	}    
} 

// Entry point for all AGK Helper calls
public class AGKHelper {
	
	static AGKLocationListener m_GPSListener = null;
	static float m_fGPSLatitude;
	static float m_fGPSLongitude;
	static float m_fGPSAltitude;
	static GoogleApiClient m_GPSClient = null;
	static boolean m_GPSRequested = false;
	static int m_GPSCheck = -1;
	static int m_ReconnectGameCenter = 0;
	static AGKGameListener m_GameListener = null;
	static GoogleApiClient m_GameClient = null;
	static int m_GameCenterLoggedIn = 0;
	static AchievementBuffer m_AllAchievements = null;
	static int isVisible = 0;
	
	public static void MinimizeApp( Activity act )
	{
		act.moveTaskToBack(true);
	}
	
	public static void QuitApp( Activity act )
	{
		act.finish();
	}
		
	public static void OnStart( Activity act )
	{
		isVisible = 1;

		// resume ad
		RunnableAd run = new RunnableAd();
		run.action = 8;
		run.act = act;
		act.runOnUiThread( run );
		
		if ( m_GPSRequested && m_GPSClient != null && !m_GPSClient.isConnected() && !m_GPSClient.isConnecting() ) 
		{
			m_GPSClient.connect();
		}
		
		if ( m_GameClient != null && !m_GameClient.isConnected() && !m_GameClient.isConnected() )
		{
			if ( m_ReconnectGameCenter == 1 )
			{
				m_GameClient.connect();
			}
			else if ( m_ReconnectGameCenter == 2 )
			{
				m_ReconnectGameCenter++;
				AGKHelper.ShowMessage( act, "Unable to sign in to Google Play Games" );
			}
		}
	}
	
	public static void OnStop( Activity act )
	{
		isVisible = 0;

		// pause ad
		RunnableAd run = new RunnableAd();
		run.action = 7;
		run.act = act;
		act.runOnUiThread( run );
		
		if ( m_GPSClient != null ) 
		{
			if ( m_GPSClient.isConnected() ) 
			{
				LocationServices.FusedLocationApi.removeLocationUpdates(m_GPSClient, m_GPSListener);
			}
			m_GPSClient.disconnect();
		}
	}
	
	private static boolean servicesConnected(Activity act) {
        int resultCode = GooglePlayServicesUtil.isGooglePlayServicesAvailable(act);
        if (ConnectionResult.SUCCESS == resultCode) {
            return true;
        } else {
            ShowMessage(act, "Google Play Services unavailable");
            return false;
        }
    }
	
	public static int GetGPSExists( Activity act )
	{
		if ( m_GPSCheck < 0 ) m_GPSCheck = servicesConnected(act) ? 1 : 0;
		return m_GPSCheck;
	}
	
	public static void StartGPSTracking( Activity act )
	{
		if ( m_GPSListener == null )
		{
			m_GPSListener = new AGKLocationListener();
			m_GPSListener.act = act;
		}
		
		if ( m_GPSClient == null )
		{
			m_GPSClient = new GoogleApiClient.Builder(act)
											 .addApi(LocationServices.API)
											 .addConnectionCallbacks(m_GPSListener)
											 .addOnConnectionFailedListener(m_GPSListener)
											 .build();
		}
		
		m_GPSRequested = true;
		if ( !m_GPSClient.isConnected() && !m_GPSClient.isConnecting() ) m_GPSClient.connect();
	}
	
	public static void StopGPSTracking()
	{
		if ( m_GPSClient != null ) 
		{
			if ( m_GPSClient.isConnected() ) 
			{
				LocationServices.FusedLocationApi.removeLocationUpdates(m_GPSClient, m_GPSListener);
			}
			m_GPSClient.disconnect();
		}
		m_GPSRequested = false;
	}
	
	public static float GetGPSLatitude()
	{
		return m_fGPSLatitude;
	}
	
	public static float GetGPSLongitude()
	{
		return m_fGPSLongitude;
	}
	
	public static float GetGPSAltitude()
	{
		return m_fGPSAltitude;
	}
	
	// GameCenter
	public static int GetGameCenterExists( Activity act )
	{
		if ( m_GPSCheck < 0 ) m_GPSCheck = servicesConnected(act) ? 1 : 0;
		return m_GPSCheck;
	}
	
	public static void GameCenterSetup( Activity act )
	{
		if ( m_GameListener == null )
		{
			m_GameListener = new AGKGameListener();
			m_GameListener.act = act;
		}
		
		if ( m_GameClient == null )
		{
			m_GameClient = new GoogleApiClient.Builder(act)
            								  .addConnectionCallbacks(m_GameListener)
            								  .addOnConnectionFailedListener(m_GameListener)
            								  .addApi(Plus.API).addScope(Plus.SCOPE_PLUS_LOGIN)
            								  .addApi(Games.API).addScope(Games.SCOPE_GAMES)
            								  .build();
		}
		
		m_GameCenterLoggedIn = 0;
	}
	
	public static void GameCenterLogin( Activity act )
	{
		if ( m_GameClient == null ) return;
		
		if ( !m_GameClient.isConnected() && !m_GameClient.isConnecting() )
		{
			m_ReconnectGameCenter = 0;
			m_GameClient.connect();
		}
	}
	
	public static int GetGameCenterLoggedIn()
	{
		return m_GameCenterLoggedIn;
	}
	
	public static void GameCenterSubmitAchievement( String szAchievementID, int iPercentageComplete )
	{
		if (m_GameClient == null) return;
		if (!m_GameClient.isConnected()) return;

		if (m_AllAchievements == null) return;

		Achievement ach;
		Iterator<Achievement> aIterator = m_AllAchievements.iterator();

		while (aIterator.hasNext()) {
			ach = aIterator.next();
			if (szAchievementID.equals(ach.getAchievementId())) {
				if (ach.getType() == Achievement.TYPE_INCREMENTAL) {
					Games.Achievements.setSteps(m_GameClient, szAchievementID, iPercentageComplete);
				} else {
					Games.Achievements.unlock(m_GameClient, szAchievementID);
				}
				break;
			}
		}
	}
	
	public static void GameCenterAchievementsShow( Activity act )
	{
		if ( m_GameClient == null ) return;
		if ( !m_GameClient.isConnected() ) return;
		
		Looper.prepare();
		act.startActivityForResult(Games.Achievements.getAchievementsIntent(m_GameClient),0);
	}
	
	public static void GameCenterSubmitScore( String szBoardID, int iScore )
	{
		if ( m_GameClient == null ) return;
		if ( !m_GameClient.isConnected() ) return;
		
		Games.Leaderboards.submitScore(m_GameClient, szBoardID, iScore);
	}
	
	public static void GameCenterShowLeaderBoard( Activity act, String szBoardID )
	{
		if ( m_GameClient == null ) return;
		if ( !m_GameClient.isConnected() ) return;
		
		Looper.prepare();
		act.startActivityForResult(Games.Leaderboards.getLeaderboardIntent(m_GameClient,szBoardID),0);
	}
	// End GameCenter

	@SuppressWarnings("deprecation")
	public static String GetIP(Activity act)
	{
		WifiManager wm = (WifiManager) act.getSystemService(Context.WIFI_SERVICE);
		return Formatter.formatIpAddress(wm.getConnectionInfo().getIpAddress());
	}
	
	public static int GetDisplayWidth( Activity act )
	{
		//Display display = act.getWindowManager().getDefaultDisplay(); 
		//return display.getWidth();
		
		DisplayMetrics displaymetrics = new DisplayMetrics();
		act.getWindowManager().getDefaultDisplay().getMetrics(displaymetrics);
		int screenWidth = displaymetrics.widthPixels;
		return screenWidth;
	}
	
	public static int GetDisplayHeight( Activity act )
	{
		//Display display = act.getWindowManager().getDefaultDisplay(); 
		//return display.getHeight();
		
		DisplayMetrics displaymetrics = new DisplayMetrics();
		act.getWindowManager().getDefaultDisplay().getMetrics(displaymetrics);
		int screenHeight = displaymetrics.heightPixels;
		return screenHeight;
	}
	
	// Edit box input
	static EditText mTextInput = null;
	static boolean mTextFinished = false;
	static boolean mTextHiding = false;
	public static int GetInputFinished( Activity act )
	{
		return mTextFinished ? 1 : 0;
	}
	
	public static int GetInputCursor( Activity act )
	{
		if ( mTextInput == null ) return 0;
		return mTextInput.getSelectionStart();
	}
	
	public static String GetInputText( Activity act )
	{
		if ( mTextInput == null ) return "";
		return mTextInput.getText().toString();
	}
	
	public static void SetInputText( Activity act, String text, int cursorpos )
	{
		//if ( mTextInput == null ) return;
		
		RunnableKeyboard run = new RunnableKeyboard();
		run.act = act;
		run.action = 3;
		run.text = text;
		run.cursorpos = cursorpos;
		act.runOnUiThread( run );
	}
	
	public static void ShowKeyboard( Activity act, int multiline )
	{
		//InputMethodManager lInputMethodManager = (InputMethodManager)act.getSystemService(Context.INPUT_METHOD_SERVICE);
		//lInputMethodManager.showSoftInput( act.getWindow().getDecorView(), 0 );
		
		mTextFinished = false;
		
		if ( mTextInput != null && !mTextHiding ) 
		{
			RunnableKeyboard run = new RunnableKeyboard();
			run.act = act;
			run.action = 4;
			run.cursorpos = -1;
			act.runOnUiThread( run );
			return;
		}
		
		mTextHiding = false;
		
		RunnableKeyboard run = new RunnableKeyboard();
		run.act = act;
		run.action = 1;
		run.multiline = multiline;
		run.cursorpos = -1;
		act.runOnUiThread( run );
	}
	
	public static void HideKeyboard( Activity act )
	{
		mTextFinished = true;
		mTextHiding = true;
		
		if ( mTextInput == null ) 
		{
			InputMethodManager lInputMethodManager = (InputMethodManager)act.getSystemService(Context.INPUT_METHOD_SERVICE);
			lInputMethodManager.hideSoftInputFromWindow( act.getWindow().getDecorView().getWindowToken(), 0 );
			return;
		}
		
		RunnableKeyboard run = new RunnableKeyboard();
		run.act = act;
		run.action = 2;
		act.runOnUiThread( run );
	}
	
	public static String UpdateInputDevices()
	{
		String returnValues = "";
		int ids[] = InputDevice.getDeviceIds();
		
		// find all device IDs that are joysticks
		for ( int i = 0; i < ids.length; i++ )
		{
			InputDevice device = InputDevice.getDevice( ids[i] );
			if ( (device.getSources() & InputDevice.SOURCE_CLASS_JOYSTICK) != 0 )
			{
				if ( returnValues.length() > 0 ) returnValues += ":";
				returnValues += Integer.toString(ids[i]);
			}
		}
		return returnValues;
	}
	
	public static void RefreshMediaPath( Activity act, String path )
	{
		MediaScannerConnection.scanFile(act, new String[]{path}, null, null);
	}
	
	public static int hasStartedVideo = 0;
	public static int videoLoaded = 0;
	public static final Object videoLock = new Object();
	public static float g_fVideoVolume = 100; 
	
	public static void LoadVideo( Activity act, String filename, int type )
	{
		Log.i("Video","Load Video");
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 1;
		video.filename = filename;
		video.fileType = type;
		act.runOnUiThread(video);
		videoLoaded = 1;
	} 
	
	public static void SetVideoDimensions( Activity act, int x, int y, int width, int height )
	{
		Log.i("Video","Set Dimensions");
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 2;
		video.m_x = x;
		video.m_y = y;
		video.m_width = width;
		video.m_height = height;
		act.runOnUiThread(video);
	}
	
	public static void PlayVideo( Activity act )
	{
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 3;
		act.runOnUiThread(video);
		
		hasStartedVideo = 1;
	}
	
	public static void PauseVideo( Activity act )
	{
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 5;
		act.runOnUiThread(video);
		
		hasStartedVideo = 0;
	}
	
	public static void StopVideo( Activity act )
	{
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 4;
		act.runOnUiThread(video);
		
		hasStartedVideo = 0;
	}
	
	public static void DeleteVideo( Activity act )
	{
		RunnableVideo video = new RunnableVideo();
		video.act = act;
		video.action = 6;
		act.runOnUiThread(video);
		
		hasStartedVideo = 0;
		videoLoaded = 0;
	}
	
	public static int GetVideoPlaying( Activity act )
	{
		return hasStartedVideo;
	}
	
	public static float GetVideoValue( Activity act, int value )
	{
		if ( RunnableVideo.video == null ) return videoLoaded==1 ? 0 : -1;
		if ( RunnableVideo.video.m_filename.equals("Error") ) return -1;
		if ( RunnableVideo.video.m_filename.equals("") ) return videoLoaded==1 ? 0 : -1;
		
		switch(value)
		{
			case 1: // video position
			{
				synchronized( videoLock ) 
				{
					if ( RunnableVideo.video.player == null ) return 0;
					return RunnableVideo.video.player.getCurrentPosition()/1000.0f;
				}
			}
			case 2: return RunnableVideo.video.videoDuration/1000.0f; // video duration
			case 3: return RunnableVideo.video.videoWidth; // video width
			case 4: return RunnableVideo.video.videoHeight; // video height
		}
		
		return 0;
	}
	
	public static void SetVideoVolume( float volume )
	{
		g_fVideoVolume = volume;
		if ( g_fVideoVolume > 99 ) g_fVideoVolume = 99;
		if ( g_fVideoVolume < 0 ) g_fVideoVolume = 0;
		if ( RunnableVideo.video == null || RunnableVideo.video.player == null ) return;
		
		float log1=(float)(Math.log(100-g_fVideoVolume)/Math.log(100));
		RunnableVideo.video.player.setVolume( 1-log1, 1-log1 );
	}
	
	public static void ShowMessage( Activity act, String msg )
	{
		RunnableMessage run = new RunnableMessage();
		run.act = act;
		run.msg = msg;
		act.runOnUiThread(run);
	}
	
	public static void CreateAd(Activity act, String publisherID, int horz, int vert, int offsetX, int offsetY)
	{
		RunnableAd run = new RunnableAd();
		run.pubID = publisherID;
		run.horz = horz;
		run.vert = vert;
		run.offsetX = offsetX;
		run.offsetY = offsetY;
		run.action = 1;
		run.act = act;
		act.runOnUiThread(run);
	}
	
	public static void CacheFullscreenAd(Activity act, String publisherID)
	{
		RunnableAd run = new RunnableAd();
		run.pubID = publisherID;
		run.action = 10;
		run.act = act;
		act.runOnUiThread(run);
	}
	
	public static void CreateFullscreenAd(Activity act, String publisherID)
	{
		RunnableAd run = new RunnableAd();
		run.pubID = publisherID;
		run.action = 9;
		run.act = act;
		act.runOnUiThread( run );
	}
	
	public static void PositionAd(Activity act, int horz, int vert, int offsetX, int offsetY)
	{
		RunnableAd run = new RunnableAd();
		run.horz = horz;
		run.vert = vert;
		run.offsetX = offsetX;
		run.offsetY = offsetY;
		run.action = 2;
		run.act = act;
		act.runOnUiThread( run );
	}
	
	public static void DeleteAd(Activity act)
	{
		RunnableAd run = new RunnableAd();
		run.action = 3;
		run.act = act;
		act.runOnUiThread( run );
	}
	
	public static void RefreshAd(Activity act)
	{
		RunnableAd run = new RunnableAd();
		run.action = 4;
		run.act = act;
		act.runOnUiThread( run );
	}
	
	public static void SetAdVisible(Activity act, int visible)
	{
		RunnableAd run = new RunnableAd();
		run.action = visible>0 ? 6 : 5;
		run.act = act;
		act.runOnUiThread( run );
	}

	public static void SetChartboostDetails( Activity act, String publisherID, String publisherID2 )
	{
		RunnableChartboost.AppID = publisherID;
		RunnableChartboost.AppSig = publisherID2;

		RunnableChartboost run = new RunnableChartboost();
		run.action = 1;
		run.act = act;
		act.runOnUiThread( run );
	}

	public static void CreateFullscreenAdChartboost(Activity act, int type)
	{
		RunnableChartboost run = new RunnableChartboost();
		run.action = 3;
		run.act = act;
		act.runOnUiThread( run );
	}

	public static void SetAmazonAdDetails( Activity act, String publisherID )
	{
		RunnableAmazonAds.AppID = publisherID;

		RunnableAmazonAds run = new RunnableAmazonAds();
		run.action = 1;
		run.act = act;
		act.runOnUiThread( run );
	}

	public static void SetAmazonAdTesting( Activity act, int testing )
	{
		RunnableAmazonAds.testing = testing;

		RunnableAmazonAds run = new RunnableAmazonAds();
		run.action = 2;
		run.act = act;
		act.runOnUiThread(run);
	}

	public static void CreateFullscreenAdAmazon(Activity act)
	{
		RunnableAmazonAds run = new RunnableAmazonAds();
		run.action = 3;
		run.act = act;
		act.runOnUiThread( run );
	}

	public static int GetFullscreenLoadedAdMob()
	{
		return RunnableAd.cached;
	}

	public static int GetFullscreenLoadedChartboost()
	{
		return RunnableChartboost.cached;
	}

	public static int GetFullscreenLoadedAmazon()
	{
		return RunnableAmazonAds.cached;
	}

	// local notifications
	public static void SetNotification( Activity act, int id, int unixtime, String message )
	{
		Intent intent = new Intent(act, NotificationAlarmReceiver.class);
		intent.putExtra("title", act.getString(R.string.app_name));
		intent.putExtra("message", message);
		intent.putExtra("id",id);
		PendingIntent sender = PendingIntent.getBroadcast(act, id, intent, 0);

		// Get the AlarmManager service
		AlarmManager am = (AlarmManager) act.getSystemService(Context.ALARM_SERVICE);
		am.set(AlarmManager.RTC_WAKEUP, unixtime * 1000L, sender);
	}

	public static void CancelNotification( Activity act, int id )
	{
		Intent intent = new Intent(act, NotificationAlarmReceiver.class);
		PendingIntent sender = PendingIntent.getBroadcast(act, id, intent, 0);

		// Get the AlarmManager service
		AlarmManager am = (AlarmManager) act.getSystemService(Context.ALARM_SERVICE);
		am.cancel(sender);
	}
	
	public static void SetOrientation( Activity act, int orien )
	{
		act.setRequestedOrientation( orien );
	}
	
	public static int GetOrientation( Activity act )
	{
		return act.getWindowManager().getDefaultDisplay().getRotation();
	}
	
	public static String GetDeviceID(Activity nativeactivityptr)
	{
		// This ID will remain constant for this device until a factory reset is performed
		String uuid = Secure.getString(nativeactivityptr.getContentResolver(), Secure.ANDROID_ID);		
		return uuid;
	}
	
	// ********************
	// In App Purchase
	// ********************
	
	public static final int MAX_PRODUCTS = 25;
	public static int g_iPurchaseState = 1;
	public static int g_iNumProducts = 0; 
	public static int[] g_iPurchaseProductStates = new int[MAX_PRODUCTS];
	public static String[] g_sPurchaseProductNames = new String[MAX_PRODUCTS];
	public static String[] g_sPurchaseProductPrice = new String[MAX_PRODUCTS];
	public static String[] g_sPurchaseProductDesc = new String[MAX_PRODUCTS];
	public static int[] g_iPurchaseProductTypes = new int[MAX_PRODUCTS];
	public static String base64EncodedPublicKey = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEApOzYM9UojDHwdf+EpvYyNksRzclcVhSWwsVBvHX/iAwl6TtVWwUnYRJowGRQe89VplxDE1BCZpbtfCKKUf/M+7Bd4L1TG8Oje5+cccdX9KPvSVd4ZQQOp/qnkkpmxehY6p2h1t2yII+8PyPtpGkDq6ns7z3lyVQtYBd51xm40ma0wspu/w8HeEkecOIjZx5CFhQyTVWetgfRow2u5eeG9Y0Y2nJ6LDYhSPr3Fgq02PEtfvYxuZmu465UOCiylYxgxPXIP2R5X6ciqoxxQHi9sKux8dl8Ale8erAKc7n6HGdtIkzpIOTFX8/xYjycfsN64gW2KoR3a2j7Z9kpQOFlMwIDAQAB";
	public static IabHelper mHelper = null;
	public static int g_iIAPID = -1;
	public static Activity g_pAct = null;
	public static final Object iapLock = new Object();
	
	static IabHelper.QueryInventoryFinishedListener mGotInventoryListener = new IabHelper.QueryInventoryFinishedListener() {
        public void onQueryInventoryFinished(IabResult result, Inventory inventory) {
            Log.d("IAB InventoryFinished", "Query inventory finished.");
            if (result.isFailure()) {
                Log.e("IAB InventoryFinished","Failed to query inventory: " + result);
                return;
            }

            Log.d("IAB InventoryFinished", "Query inventory was successful.");
            
            for( int i = 0; i < g_iNumProducts; i++ )
            {
	            Purchase purchased = inventory.getPurchase(g_sPurchaseProductNames[i]);
	            if (purchased != null)
	            {
	            	// is it consumable?
	            	if ( g_iPurchaseProductTypes[i] == 1 ) mHelper.consumeAsync(inventory.getPurchase(g_sPurchaseProductNames[i]), mConsumeFinishedListener);
	            	else 
	            	{
	            		g_iPurchaseProductStates[i] = 1;
	            		Log.d("IAB InventoryFinished", "Remembered purchase: " + g_sPurchaseProductNames[i]);
	            	}
	            }

				SkuDetails details = inventory.getSkuDetails(g_sPurchaseProductNames[i]);
				if ( details != null )
				{
					Log.d("IAB InventoryFinished", "SKU Details for " + g_sPurchaseProductNames[i] + " Desc: " + g_sPurchaseProductDesc[i] + ", Price: " + g_sPurchaseProductPrice[i]);

					// if currency symbol is one we can display in AGK then keep it, otherwise append currency code to price and remove symbol
					String price = details.getPrice();
					char symbol = price.charAt(0);
					String numbers = "0123456789.,";
					int index = 0;
					while( index < price.length() && !numbers.contains(price.substring(index,index+1)) ) index++;
					if ( index == 0 ) symbol = price.charAt(price.length()-1);
					price = price.substring(index);
					index = price.length()-1;
					while( index > 0 && !numbers.contains(price.substring(index,index+1)) ) index--;
					price = price.substring(0,index+1);

					switch( symbol )
					{
						case '$': price = "$" + price; break;
						case 'p': price = "p" + price; break; // can't transfer pound character to AGK easily, so use a place holder and replace it in AGK
						case 'e': price = "e" + price; break; // can't transfer euro character to AGK easily, so use a place holder and replace it in AGK
						default: price = price + " " + details.getCurrency();
					}

					synchronized (iapLock)
					{
						g_sPurchaseProductPrice[i] = price;
						g_sPurchaseProductDesc[i] = ConvertString(details.getDescription());
					}
				}
            }
        }
    };
    
    static IabHelper.OnIabPurchaseFinishedListener mPurchaseFinishedListener = new IabHelper.OnIabPurchaseFinishedListener() {
        public void onIabPurchaseFinished(IabResult result, Purchase purchase) {
            Log.d("IAB PurchaseFinished", "Purchase finished: " + result + ", purchase: " + purchase);
            if (result.isFailure()) {
                Log.e("IAB PurchaseFinished","Error purchasing: " + result);
                if ( result.getMessage().contains("User cancelled") == false ) AGKHelper.ShowMessage(g_pAct, "Purchase Result: " + result.getMessage());
                g_iPurchaseState = 1;
                return;
            }
            
            for( int i = 0; i < g_iNumProducts; i++ )
            {
            	if ( purchase.getSku().equals(g_sPurchaseProductNames[i]) )
	            {
	            	// is it consumable?
	            	if ( g_iPurchaseProductTypes[i] == 1 ) mHelper.consumeAsync(purchase, mConsumeFinishedListener);
	            	else 
	            	{
	            		g_iPurchaseProductStates[i] = 1;
	            		g_iPurchaseState = 1;
	            		Log.d("IAB PurchaseFinished", "Purchase successful: " + g_sPurchaseProductNames[i]);
	            	}
	            	return;
	            }
            }

            g_iPurchaseState = 1;
            Log.e("IAB PurchaseFinished", "Purchase failure SKU not found: " + purchase.getSku());
        }
    };
    
    // Called when consumption is complete
    static IabHelper.OnConsumeFinishedListener mConsumeFinishedListener = new IabHelper.OnConsumeFinishedListener() {
        public void onConsumeFinished(Purchase purchase, IabResult result) {
            Log.d("IAB ConsumeFinished", "Consumption finished. Purchase: " + purchase + ", result: " + result);

            int ID = -1;
            for( int i = 0; i < g_iNumProducts; i++ )
            {
            	if ( purchase.getSku().equals(g_sPurchaseProductNames[i]) ) 
            	{
            		ID = i;
            		break;
            	}
            }
            
            if ( ID < 0 ) 
            {
            	Log.e("IAB ConsumeFinished","Error while consuming: SKU not found " + purchase.getSku());
            	g_iPurchaseState = 1;
            	return;
            }
            
            if (result.isSuccess()) {
            	g_iPurchaseProductStates[ID] = 1;
                Log.d("IAB ConsumeFinished", "Consumption successful. Provisioning.");
            }
            else {
                Log.e("IAB ConsumeFinished","Error while consuming: " + result);
                AGKHelper.ShowMessage(g_pAct, "Error while consuming purchase: " + result);
            }
            
            g_iPurchaseState = 1;
        }
    };
    
    public static void iapSetKeyData( String publicKey, String developerID )
	{
    	base64EncodedPublicKey = publicKey;
	}
	
	public static void iapAddProduct( String name, int ID, int type )
	{		
		name = name.toLowerCase();
		Log.i("IAB AddProduct","Adding: " + name + " to ID: " + Integer.toString(ID));
		if ( ID < 0 || ID >= MAX_PRODUCTS ) return;
		g_iPurchaseProductStates[ ID ] = 0;
		g_sPurchaseProductNames[ ID ] = name;
		g_iPurchaseProductTypes[ ID ] = type;
		//Log.i("IAB AddProduct","Added: " + name);
		if ( ID+1 > g_iNumProducts ) g_iNumProducts = ID+1;
    }
	
	public static void iapSetup( Activity act )
	{		
		g_pAct = act;
		mHelper = new IabHelper(act, base64EncodedPublicKey);
		mHelper.enableDebugLogging(true);
		
		mHelper.startSetup(new IabHelper.OnIabSetupFinishedListener() {
			public void onIabSetupFinished(IabResult result) {
				Log.d("In App Billing", "Setup finished.");

				if (!result.isSuccess()) {
					Log.e("In App Billing", "Problem setting up in-app billing: " + result);
					return;
				}

				// Hooray, IAB is fully set up. Now, let's get an inventory of stuff we own.
				Log.d("In App Billing", "Setup successful. Querying inventory.");

				// create a list of all products
				ArrayList<String> skus = new ArrayList<String>();
				for (int i = 0; i < g_iNumProducts; i++) skus.add(g_sPurchaseProductNames[i]);

				mHelper.queryInventoryAsync(true, skus, mGotInventoryListener);
			}
		});
    }
	
	public static void iapMakePurchase( Activity act, int ID )
	{		
		if ( ID < 0 || ID >= MAX_PRODUCTS ) return;
		if ( g_iPurchaseProductTypes[ ID ] == 0 && g_iPurchaseProductStates[ ID ] == 1 ) 
		{
			AGKHelper.ShowMessage(act,"You have already purchased that item");
			return; // non-consumable item already purchased
		}
		
		g_iPurchaseState = 0;
		g_iPurchaseProductStates[ ID ] = 0;
		g_iIAPID = ID;
		Log.i("IAB MakePurchase", "Buying " + g_sPurchaseProductNames[ID]);
		
		Intent myIntent = new Intent(act, IAPActivity.class);
		act.startActivity(myIntent);
    }
	
	public static int iapCheckPurchaseState()
	{
		return g_iPurchaseState;
	}
	
	public static int iapCheckPurchase( int ID )
	{
		if ( ID < 0 || ID >= MAX_PRODUCTS ) return 0;
		return g_iPurchaseProductStates[ ID ];
	}

	public static String iapGetPrice( int ID )
	{
		synchronized (iapLock)
		{
			if (ID < 0 || ID >= MAX_PRODUCTS || g_sPurchaseProductPrice[ID] == null) return "";
			return g_sPurchaseProductPrice[ID];
		}
	}

	public static String iapGetDescription( int ID )
	{
		synchronized (iapLock)
		{
			if (ID < 0 || ID >= MAX_PRODUCTS || g_sPurchaseProductDesc[ID] == null) return "";
			return g_sPurchaseProductDesc[ID];
		}
	}
	
	// ******************
	// Push Notifications
	// ******************
	
	public static String GCM_product_number = "210280521980"; // TGC
	//public static String GCM_product_number = "1083864810983"; // Focus
	public static String GCM_PACKAGE_NAME = "";
	public static String GCM_PNRegID = "";
	
	public static void setPushNotificationKeys( String key1, String key2 )
	{
		GCM_product_number = key1;
	}
	
	public static int registerPushNotification( Activity nativeactivityptr )
	{
		GCM_PACKAGE_NAME = nativeactivityptr.getApplicationContext().getPackageName();
		
		try
		{
			GCMRegistrar.checkDevice(nativeactivityptr);
			GCMRegistrar.checkManifest(nativeactivityptr);
			String regId = GCMRegistrar.getRegistrationId(nativeactivityptr);
			if (regId.equals("")) {
			  GCMRegistrar.register(nativeactivityptr, GCM_product_number);
			}
			else 
			{
				GCM_PNRegID = regId;
			}
		}
		catch( Exception e )
		{
			Log.e("Push Notification", e.toString());
			return 0;
		}
				
		return 1;
	}
	
	public static String getPNRegID()
	{
		return GCM_PNRegID;
	}
	
	public static String GetAppName(Activity act)
	{
		final PackageManager pm = act.getApplicationContext().getPackageManager();
		
		ApplicationInfo ai;
		try 
		{
		    ai = pm.getApplicationInfo( act.getPackageName(), 0);
		} 
		catch (final NameNotFoundException e) 
		{
		    ai = null;
		}
		final String applicationName = (String) (ai != null ? pm.getApplicationLabel(ai) : "unknown");
		return applicationName;
	}
	
	// image chooser code
	//private static MyJavaActivity myActivity = null;
	//private static MyJavaActivity imageActivity = null;
    private static String storeimagepath = null;
	public static void StoreImagePath(String path) { storeimagepath=path; }
	
	// Function to launch Choose Image intent
	public static String StartChooseImage(Activity nativeactivityptr)
	{
		// Ensure we can create a new activity in this static function
		Looper.prepare();
		
		// Create new intent and launch it (choose image)
		Intent myIntent = new Intent(nativeactivityptr, MyJavaActivity.class);
		nativeactivityptr.startActivity(myIntent);
		
		// return immediately - fun string return (can be replaced with boolean/int)
		return "success";
    }
	
	// Retrieve image path string when we return to main NativeActivity
	public static String GetChosenImagePath()
	{
		if ( storeimagepath!=null )
			return storeimagepath;
		else
			return "";
    }
	
	// camera
	public static void CaptureImage(Activity nativeactivityptr)
	{
		// Ensure we can create a new activity in this static function
		Looper.prepare();
				
		Intent cameraIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
		cameraIntent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.parse("file:///sdcard/capturedimage.jpg"));
		nativeactivityptr.startActivity(cameraIntent);    
    }
	
	public static String GetLanguage()
	{
		return Locale.getDefault().getLanguage();
	}
	
	public static int isNetworkAvailable( Activity act ) 
	{
	    ConnectivityManager connectivityManager = (ConnectivityManager) act.getSystemService(Context.CONNECTIVITY_SERVICE);
	    NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
	    if ( activeNetworkInfo != null && activeNetworkInfo.isConnected() ) return 1;
	    else return 0;
	}
	
	// Facebook
	static int facebookLoginState = 1;
	static String appID = "";
		
	public static void FacebookLogin(Activity act, String ID)
	{
		appID = ID;
		facebookLoginState = 1;
		Looper.prepare();
		
		Intent myIntent = new Intent(act, MyFacebookActivity.class);
		act.startActivity(myIntent);
	}
	
	public static void FacebookLogout()
	{
		facebookLoginState = 1;
		Session session = Session.getActiveSession();
        if ( session != null && !session.isClosed() ) 
        {
            session.closeAndClearTokenInformation();
        }
        Session.setActiveSession(null);
        facebookLoginState = 1;
	}
	
	public static int FacebookGetLoginState()
	{
		if( facebookLoginState == 1 ) return 0;
		if ( Session.getActiveSession() == null ) return -1;
		{
			if( Session.getActiveSession().getAccessToken().equals("") )
			{
				FacebookLogout();
				return -1;
			}
		}
		return 1; 
	}
	
	public static String FacebookGetAccessToken()
	{
		//Log.e("AGK",Session.getActiveSession().getAccessToken());
		if ( facebookLoginState == 1 ) return "";
		if ( Session.getActiveSession() == null ) return "Error";
		return Session.getActiveSession().getAccessToken();
	}
	
	public static void FacebookPost( Activity act, String szID, String szLink, String szPicture, String szName, String szCaption, String szDescription )
	{
		if ( Session.getActiveSession() == null )
		{
			AGKHelper.ShowMessage(act, "Unable to share on Facebook as you are not logged in");
		}
		else
		{
			RunnableFacebook feed = new RunnableFacebook();
			feed.szID = szID;
			feed.szLink = szLink;
			feed.szPicture = szPicture;
			feed.szName = szName;
			feed.szCaption = szCaption;
			feed.szDescription = szDescription;
			feed.act = act;
			feed.session = Session.getActiveSession();
			act.runOnUiThread( feed );
		}
	}
	
	public static String ConvertString( String s )
	{
		String s2 = java.text.Normalizer.normalize(s, java.text.Normalizer.Form.NFD).replaceAll("\\p{InCombiningDiacriticalMarks}+","");
		return s2;
	}
	
	public static void GenerateCrashReport(Activity act)
	{
		Process mLogcatProc = null;
	    try 
	    {
			mLogcatProc = Runtime.getRuntime().exec( new String[] {"logcat", "-d", "*:V" });
			
			InputStream is = mLogcatProc.getInputStream();
			
			SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd-hh-mm-ss");
			String format = s.format(new Date());
	    
		   // File f = new File("/sdcard/crashreport "+format+".txt");
			File f = new File("/sdcard/crashreport.txt");
		    OutputStream os;
			os = new FileOutputStream(f);
		
			byte[] buffer = new byte[1024];
			int bytesRead;
        
			while ((bytesRead = is.read(buffer)) != -1)
			{
			    os.write(buffer, 0, bytesRead);
			}
		
        	//is.close();
			os.close();
			
			Intent emailIntent = new Intent(android.content.Intent.ACTION_SEND);
			emailIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			emailIntent.putExtra(android.content.Intent.EXTRA_EMAIL, new String[]{"paul@thegamecreators.com"});
			emailIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, "AGK Bug Report");
			emailIntent.putExtra(android.content.Intent.EXTRA_TEXT, "Bug report attached. Any additional information: ");

			String rawFolderPath = "file:///mnt/sdcard/crashreport.txt";

			// Here my file name is shortcuts.pdf which i have stored in /res/raw folder
			Uri emailUri = Uri.parse(rawFolderPath );
			emailIntent.putExtra(Intent.EXTRA_STREAM, emailUri);
			emailIntent.setType("text/plain");
			act.startActivity(Intent.createChooser(emailIntent, "Send bug report..."));
		} 
	    catch (IOException e) 
	    {
			e.printStackTrace();
		}
	}
	
	public static void setExpansionKey( String key )
	{
		
	}
	
	public static void SetExpansionVersion(int version)
	{
		
	}
	
	public static int GetExpansionState(Activity act)
	{
		return 0;
	}
	
	public static void DownloadExpansion(Activity act)
	{
		
	}
	
	public static float GetExpansionProgress(Activity act)
	{
		return 0;
	}

public static void SaveSharedVariable( Activity act, String varName, String varValue )
{
	SharedPreferences sharedPref = act.getSharedPreferences( "agksharedvariables", Context.MODE_PRIVATE );
	SharedPreferences.Editor edit = sharedPref.edit();
	edit.putString( varName, varValue );
	edit.apply();
}

public static String LoadSharedVariable( Activity act, String varName, String defaultValue )
{
	SharedPreferences sharedPref = act.getSharedPreferences( "agksharedvariables", Context.MODE_PRIVATE );
	return sharedPref.getString( varName, defaultValue );
}

public static void DeleteSharedVariable( Activity act, String varName )
{
	SharedPreferences sharedPref = act.getSharedPreferences( "agksharedvariables", Context.MODE_PRIVATE );
	SharedPreferences.Editor edit = sharedPref.edit();
	edit.remove(varName);
	edit.apply();
}
}
