/// @file app.js
/// @brief main client module, AngularJS application with routing

angular.module('myApp', ['ngRoute', 'pascalprecht.translate', 'myAppControllers', 'myAppServices'] )
    .config(['$routeProvider', '$translateProvider',
             function($routeProvider, $translateProvider) {
                  $routeProvider.when('/main', {  //widok logowania
                     templateUrl: 'views/main.html',
                 });
                 $routeProvider.when('/play', {  //widok gry
                     templateUrl: 'views/play.html',
                 });
                 $routeProvider.otherwise( {
                     redirectTo: '/main'
                 });
                 $translateProvider.useStaticFilesLoader({
                      prefix: 'lang/',
                      suffix: '.json' });
                 $translateProvider.preferredLanguage('en');
             }]);

