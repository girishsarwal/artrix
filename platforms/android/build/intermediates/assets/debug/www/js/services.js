angular.module('starter.services', [])

.factory('Chats', function() {
  // Might use a resource here that returns a JSON array


  // Some fake testing data
  var chats = [{
    id: 0,
    name: 'Ben Sparrow',
    lastText: 'You on your way?',
    face: 'img/ben.png'
  }, {
    id: 1,
    name: 'Max Lynx',
    lastText: 'Hey, it\'s me',
    face: 'img/max.png'
  }, {
    id: 2,
    name: 'Adam Bradleyson',
    lastText: 'I should buy a boat',
    face: 'img/adam.jpg'
  }, {
    id: 3,
    name: 'Perry Governor',
    lastText: 'Look at my mukluks!',
    face: 'img/perry.png'
  }, {
    id: 4,
    name: 'Mike Harrington',
    lastText: 'This is wicked good ice cream.',
    face: 'img/mike.png'
  }];

  return {
    all: function() {
      return chats;
    },
    remove: function(chat) {
      chats.splice(chats.indexOf(chat), 1);
    },
    get: function(chatId) {
      for (var i = 0; i < chats.length; i++) {
        if (chats[i].id === parseInt(chatId)) {
          return chats[i];
        }
      }
      return null;
    }
  };
})
.factory('Templates', function(){
  var airplane4Channel = {
      id: 1,
      name: 'New Model',
      img: 'img/P-51.jpg',
      timer: '10:00',
      mixes:[{
        source: 'CH1',
        weight: 100,
        multiplex: 2
      }, {
        source: 'CH2',
        weight: 100,
        multiplex: 2,
      },{
        source: 'CH3',
        weight: 100,
        multiplex: 2
      }, {
        source: 'CH4',
        weight: 100,
        multiplex: 2,
      }]
    };
   
  return {
    airplane4Channel: airplane4Channel
  }    
})
.factory('Models', function(){
  var models =[];
  return {
    all: function() {
      return models;
    },
    get: function (modelId){
      for (var i = 0; i < models.length; i++) {
        if (models[i].id === parseInt(modelId)) {
          return models[i];
        }
      }
      return null;
    }
  };
})
.factory('Settings', function(){
  var settings = {
    throttleWarning: true,
    switchWarning: true,
    lowBattery: {
      warning: true,
      voltage: 7.2
    },
    inactivity: {
      warning:true,
      timeout:'5.0'
    },
    mode: 2,
    voice: {
      status: true,
      volume: 5
    },
    ppm:{
      frame_length: 22500,
      sync_length: 300
    },
    statistics:{
      battery_level:10,
      is_charging: false,
    }
  };
  return settings;
});
