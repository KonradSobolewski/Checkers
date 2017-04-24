/// @file controllers.js
/// @brief AngularJS controllers


angular.module('myAppControllers', [])
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
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


/*angular.module('myAppControllers', [])
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
		 	$scope.check = function() {
				srvInfo.getCppNumber(
				function(data){
					$scope.counter = data;
				});
			};
		 }]);
*/

