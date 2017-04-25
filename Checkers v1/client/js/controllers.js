/// @file controllers.js
/// @brief AngularJS controllers




angular.module('myAppControllers', [])
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
			$scope.row = [1,2,3,4,5,6,7,8];	
			$scope.column = [1,2,3,4,5,6,7,8];
			$scope.numberFromCpp = 0;

		
			$scope.activeCpp = function(){
				srvInfo.communicateCpp(
					function(data){	
						$scope.numberFromCpp = data.number;
					});
			}; 	
			$scope.check = function(event) {
				srvInfo.sendID(
					function(data){
						$scope.counter = data;
					}, event.target.id);
			}
		 }]);



