angular.module('starter.controllers', [])
.controller('ModelsController',['$scope','DataStore', function($scope, models){

  $scope.models = models.all();
}])
.controller('PilotController', function($scope) {

})

.controller('MonitorController', function($scope) {
  
})

.controller('SettingsController', function($scope) {
  
})

.controller('PowerController', function($scope) {
  
})

.controller('ModelSettingsController', function($scope) {
  
});
