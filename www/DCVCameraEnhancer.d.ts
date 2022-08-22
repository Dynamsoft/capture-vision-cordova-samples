import { Region } from './BasicStructures';
export declare class DCVCameraEnhancer {
    private constructor();
    static createInstance(): Promise<DCVCameraEnhancer>;
    open(): Promise<void>;
    close(): Promise<void>;
    turnOnTorch(): Promise<void>;
    turnOffTorch(): Promise<void>;
    setScanRegion(region: Region): Promise<void>;
    setScanRegionVisible(isVisible: boolean): void;
}
