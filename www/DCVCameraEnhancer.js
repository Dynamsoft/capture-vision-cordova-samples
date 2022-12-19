"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.DCVCameraEnhancer = void 0;
const exec_1 = __importDefault(require("cordova/exec"));
var EnumTorchState;
(function (EnumTorchState) {
    EnumTorchState[EnumTorchState["OFF"] = 0] = "OFF";
    EnumTorchState[EnumTorchState["ON"] = 1] = "ON";
})(EnumTorchState || (EnumTorchState = {}));
class DCVCameraEnhancer {
    constructor() {
    }
    /**
    * Create an instance of DCVCameraEnhancer.
    */
    static createInstance() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => {
                resolve(new DCVCameraEnhancer());
            }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
        });
        return promise;
    }
    /**
    * Open the camera.
    */
    open() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'open', []);
        });
        return promise;
    }
    /**
    * Close the camera.
    */
    close() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'close', []);
        });
        return promise;
    }
    /**
    * Trun on the torch.
    */
    turnOnTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.ON]);
        });
        return promise;
    }
    /**
    * Trun off the torch.
    */
    turnOffTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.OFF]);
        });
        return promise;
    }
    /**
    * Specify a region of interest with a region object.
    */
    setScanRegion(region) {
        if (region) {
            region.regionMeasuredByPercentage = region.regionMeasuredByPercentage ? 1 : 0;
        }
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
        });
        return promise;
    }
    /**
    * Set whether to display the scan region.
    */
    setScanRegionVisible(isVisible) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
    }
}
exports.DCVCameraEnhancer = DCVCameraEnhancer;
