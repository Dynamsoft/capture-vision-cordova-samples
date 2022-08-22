"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.CameraEnhancer = void 0;
const exec_1 = __importDefault(require("cordova/exec"));
const CameraSettings_1 = require("./CameraSettings");
class CameraEnhancer {
    constructor() {
    }
    static createInstance() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => {
                resolve(new CameraEnhancer());
            }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
        });
        return promise;
    }
    open(errorCallback) {
        (0, exec_1.default)(null, errorCallback, 'DynamsoftCordovaPlugin', 'open', [this.htmlElement]);
    }
    close(errorCallback) {
        (0, exec_1.default)(null, errorCallback, 'DynamsoftCordovaPlugin', 'close', []);
    }
    turnOnTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(null, (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [CameraSettings_1.EnumTorchState.ON]);
        });
        return promise;
    }
    turnOffTorch() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(null, (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [CameraSettings_1.EnumTorchState.OFF]);
        });
        return promise;
    }
    setScanRegion(region) {
        if (region && region.regionMeasuredByPercentage) {
            region.regionMeasuredByPercentage = 1;
        }
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(null, (error) => reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
        });
        return promise;
    }
    setScanRegionVisible(isVisible) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
    }
}
exports.CameraEnhancer = CameraEnhancer;
