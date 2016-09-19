package com.thegamecreators.agk_player;

import android.app.NativeActivity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.NotificationCompat;
import android.util.Log;

import com.mycompany.mytemplate.R;

public class NotificationAlarmReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Log.i("Notification Alarm","Received");
        if ( AGKHelper.isVisible == 1 ) return;

        String message = intent.getStringExtra("message");
        String title = intent.getStringExtra("title");
        int id = intent.getIntExtra("id", 0);

        NotificationManager notificationManager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);

        //Intent intent2 = new Intent(this, NotificationReceiver.class);
        //PendingIntent pIntent = PendingIntent.getActivity(this, 0, intent2, 0);

        Intent intent2 = new Intent(context, NativeActivity.class);
        PendingIntent pIntent = PendingIntent.getActivity(context, 0, intent2, 0);

        CharSequence from = title;

        Notification notif = new NotificationCompat.Builder(context)
                .setContentTitle(from)
                .setContentText(message)
                .setSmallIcon(R.drawable.icon)
                .setContentIntent(pIntent)
                .setAutoCancel(true)
                .setDefaults(Notification.DEFAULT_SOUND | Notification.DEFAULT_LIGHTS)
                .build();

        notificationManager.notify(id, notif);
    }
}