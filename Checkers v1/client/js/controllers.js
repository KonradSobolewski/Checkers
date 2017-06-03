/// @file controllers.js
/// @brief AngularJS controllers




angular.module('myAppControllers', [])
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
			$scope.row = [1,2,3,4,5,6,7,8];	
			$scope.column = [1,2,3,4,5,6,7,8];
			$scope.numberFromCpp = 0;
			$scope.classes =['blackPiece','redPiece'];
			$scope.state = 0;
			$scope.first = -1;
			$scope.second = -1;
			$scope.licznik=0;
			$scope.player=true;
		
			$scope.activeCpp = function(){
				srvInfo.communicateCpp(
					function(data){	
						$scope.numberFromCpp = data.number;
					});
			}; 


			$scope.move = function ()
			{
				$scope.player = !($scope.player);
				if ($scope.player == true)
				{
					
					// zmiana pozycji pionka
				}
				else
				{
					// zmiiana pozycji pionka AI
				}			

			};
	
			$scope.check = function(event) {
				$scope.state++;
				if ($scope.state == 1)
				{
					$scope.first= event.target.id;
				}
				else if ($scope.state == 2)
				{
					$scope.second= event.target.id;
				}
				
				if ($scope.first != -1 && $scope.second != -1)
				{	
					if($scope.first != $scope.second)
					{	srvInfo.sendID(
						function(data){
							$scope.counter = data;
						}, $scope.first,$scope.second);
						$scope.play = true;
						$scope.move();
					}
					$scope.first = -1;
					$scope.second = -1;
					$scope.state = 0;

				}

				
			}

		 }]);



