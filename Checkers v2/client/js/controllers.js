/// @file controllers.js
/// @brief AngularJS controllers




angular.module('myAppControllers', [])
		/*!
			kontroler gry
		*/
		.controller('settingsController',['$scope', 'srvInfo', function($scope, srvInfo) {
			$scope.numberFromCpp = 0; // wyświetla numer z cpp klasy Game
			$scope.state = 0;  //liczba klikniętych pół
 			$scope.first = -1;  //przechowuje id pierwszego wybranego pola
			$scope.second = -1;//przechowuje id drugiego wybranego pola
			$scope.humanState = 0;  //przechowuje słownik z info na temat gracza
			$scope.aiState = 0;  //przechowuje słownik z info na temat AI

			$scope.board = { //początkowe ustawienie pionków
				0 : './views/img/whiteCircle.png',
				2 : './views/img/whiteCircle.png',
				4 : './views/img/whiteCircle.png',
				6 : './views/img/whiteCircle.png',
				9 : './views/img/whiteCircle.png',
				11 : './views/img/whiteCircle.png',
				13 : './views/img/whiteCircle.png',
				15 : './views/img/whiteCircle.png',
				16 : './views/img/whiteCircle.png',
				18 : './views/img/whiteCircle.png',
				20 : './views/img/whiteCircle.png',
				22 : './views/img/whiteCircle.png',
				25 : '',
				27 : '',
				29 : '',
				31 : '',
				32 : '',
				34 : '',
				36 : '',
				38 : '',
				41 : './views/img/redCircle.png',
				43 : './views/img/redCircle.png',
				45 : './views/img/redCircle.png',
				47 : './views/img/redCircle.png',
				48 : './views/img/redCircle.png',
				50 : './views/img/redCircle.png',
				52 : './views/img/redCircle.png',
				54 : './views/img/redCircle.png',
				57 : './views/img/redCircle.png',
				59 : './views/img/redCircle.png',
				61 : './views/img/redCircle.png',
				63 : './views/img/redCircle.png'
			};
			// test komunikacji
			$scope.activeCpp = function(){
				srvInfo.communicateCpp(
					function(data){	
						$scope.numberFromCpp = data.number;
					});
			}; 


			//wykonanie ruchu 
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
					if(($scope.board[$scope.first] == './views/img/whiteCircle.png'  && $scope.board[$scope.second] == ''))  //tylko białego możemy ruszyć
					{	srvInfo.makeMove(
						function(data){
							$scope.humanState = data;
						}, $scope.first,$scope.second);

						if($scope.humanState.state)//good move
						{
							$scope.board[$scope.second] = './views/img/whiteCircle.png';
							$scope.board[$scope.humanState.number] = '';
							if ($scope.humanState.isHit)
							{
								$scope.board[$scope.humanState.hitPos] = '';
							}

							//AI rusza czerwonym
							srvInfo.makeAIMove( function(data){  $scope.aiState = data; });
							$scope.board[$scope.aiState.src] = '';
							$scope.board[$scope.aiState.dest] = './views/img/redCircle.png';
							if ($scope.aiState.isHit!=-1)
							{
								$scope.board[$scope.aiState.hitPos] = '';
							}
						}
						

					}
					$scope.first = -1;
					$scope.second = -1;
					$scope.state = 0;


				}

				
			}

		 }])
	/*!
			kontroler  logowania
	*/
	.controller('loginController',['$scope', 'srvInfo','$location', '$rootScope','$window', function($scope, srvInfo,$location, $rootScope,$window) {
		$scope.username = "";
		$scope.password = "";
		//logowanie do gry
		$scope.login = function()
		{
			if($scope.username!="" && $scope.password!="")
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
			}
			else
		  	{
				$window.alert("Blad logowania"); 
			}
			
		};
		//rejestracja do bazy danych
		$scope.register = function()
		{	
			if($scope.username!="" && $scope.password!="")
			{
			
				srvInfo.doRegisterUser(
				function (data)
				{		
					 if (data["session-token"])
					 { 
						 $location.path("/play");
					 }
					
				
				},$scope.username, $scope.password);
			}
			else
			{
				$window.alert("Blad rejestracji"); 
			}
			
		};

	}]);





