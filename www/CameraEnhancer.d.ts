import { Region } from './BasicStructures';
export declare class CameraEnhancer {
    private constructor();
    static createInstance(): Promise<CameraEnhancer>;
    open(errorCallback: (errorMessage: String) => void): void;
    close(errorCallback: (errorMessage: String) => void): void;
    turnOnTorch(): Promise<void>;
    turnOffTorch(): Promise<void>;
    setScanRegion(region: Region): Promise<void>;
    setScanRegionVisible(isVisible: boolean): void;
}
