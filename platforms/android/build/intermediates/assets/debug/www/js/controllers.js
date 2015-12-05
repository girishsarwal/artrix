angular.module('starter.controllers', [])
.controller('ModelsController',['$scope', '$ionicPopup', '$ionicActionSheet', 'Models','Templates','$state', function($scope, $ionicPopup, $ionicActionSheet, models, templates,$state){
  
 	$scope.models = models.all();
 	$scope.data = {
 		modelAction: 0
 	};
 	$scope.editView = false;
 	$scope.currentModel = {};

 	$scope.addModel = function(){
 		$scope.models.push(templates.airplane4Channel);
 		$state.reload();
  	};

	$scope.modelClicked = function(model){
		if($scope.editView){
			$scope.editView = false;
			return;
		}
		var actionSheet = $ionicActionSheet.show({
			buttons:[
				{text: '<center>Load</center>'},
				{text: '<center>Edit</center>'}
			],
			destructiveText: '<center>Delete</center>',
			titleText: '<center>' + model.name + '</center>',
			cancelText:'<center>Back</center>',
			cssClass: 'actionSheet',
			cancel: function(){

			},
			buttonClicked: function(button){
				$scope.editView = false;
				if(button == 1){
					$scope.editView = true;
				}
				return true;
			},
			destructiveButtonClicked: function(){
				var popup = $ionicPopup.confirm({
			  		title: 'Remove ' + model.name + '?',
			  		template: 'Are you sure? <br/><br/><span style="color:red">Make sure model is turned off!</span>'
			  	});
				popup.then(function(res){
					if(res){
						console.log('model will be deleted');
					}else {
						console.log('model will not be deleted');
					}
		  		});
		  		return true;
			}
		});
	}

	$scope.slideHasChanged = function($index){
		$scope.editView = false;
	}}
])

.controller('MonitorController', function($scope) {
  
})

.controller('SettingsController', ['$scope', 'Settings', function($scope, settings) {
  $scope.settings = settings;
}])

.controller('PowerController', ['$scope', 'Settings', function($scope, settings) {
  
}])
.controller('TabsController', ['$scope', 'Settings', function($scope, settings) {
   $scope.settings = settings;
   $scope.battery_icon_class = function(){
	if($scope.settings.statistics.battery_level > 30){
   		return 'ok';
   	}
   	return 'low'
   };
   $scope.battery_icon = function(){
   	if($scope.settings.statistics.is_charging){
   		return 'ion-battery-charging';
   	}
   	if($scope.settings.statistics.battery_level > 90){
   		return 'ion-battery-full';	
   	}
   	if($scope.settings.statistics.battery_level > 60){
		return 'ion-battery-half';	
   	} 
   	if($scope.settings.statistics.battery_level > 30){
		return 'ion-battery-low';
   	}
   	return 'ion-battery-empty';
   }
}]);
