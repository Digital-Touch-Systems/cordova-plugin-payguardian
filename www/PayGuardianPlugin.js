var exec = require("cordova/exec");

module.exports = {
    checkStatus: function (port, callback) {
        exec(function (result) {
                callback(null, result)
            },
            function (error) {
                callback(error)
            }, 'PayGuardianPlugin', 'checkStatus', [port]);
    },
    connect: function (port, callback) {
        var connected = false;
        exec(function (result) {
                //On initial connection - fire callback, otherwise fire a window event
                if (!connected) {
                    callback(null, result);
                    connected = true;
                } else {
                    //This event will be to notify of events like barcode scans
                    cordova.fireWindowEvent("PayGuardianPluginData", result);
                }
            },
            function (error) {
                callback(error)
            }, 'PayGuardianPlugin', 'connect', [port]);
    }
};
