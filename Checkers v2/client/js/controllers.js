/// @file controllers.js
/// @brief AngularJS controllers




angular.module('myAppControllers', [])
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
			$scope.numberFromCpp = 0;
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
						var selectedUser = document.getElementById(event.target.id).id;
						//document.getElementByID(event.target.id).style.backgroundImage = "url('./views/img/redCircle.png')";
    						alert("You selected " + selectedUser);
		
					}
					$scope.first = -1;
					$scope.second = -1;
					$scope.state = 0;

				}

				
			}

		 }])
	.controller('loginController',['$scope', 'srvInfo','$location', '$rootScope','$window', function($scope, srvInfo,$location, $rootScope,$window) {
		$scope.username = "";
		$scope.password = "";

		$scope.login = function()
		{
			
			srvInfo.doLoginUser(
			function (data)
			{	
				 if (data["session-token"])
				 { 
					 $location.path("/play");
				 }
				 else
				 {
					$window.alert("Blad logowania")	; 
				 }
			},$scope.username, $scope.password);
			
		};

		$scope.register = function()
		{
			
			srvInfo.doRegisterUser(
			function (data)
			{		
				 if (data["session-token"])
				 { 
					 $location.path("/play");
				 }
				 else
				 {
					$window.alert("Blad logowania")	; 
				 }
				
			},$scope.username, $scope.password);
			
		};

	}]);





