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
    static createInstance() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => {
                resolve(new DCVCameraEnhancer());
            }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
        });
        return promise;
    }
    open() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'open', []);
        });
        return promise;
    }
    close() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'close', []);
        });
        return promise;
    }
    turnOnTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.ON]);
        });
        return promise;
    }
    turnOffTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.OFF]);
        });
        return promise;
    }
    setScanRegion(region) {
        if (region) {
            region.regionMeasuredByPercentage = region.regionMeasuredByPercentage ? 1 : 0;
        }
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
        });
        return promise;
    }
    setScanRegionVisible(isVisible) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
    }
}
exports.DCVCameraEnhancer = DCVCameraEnhancer;
