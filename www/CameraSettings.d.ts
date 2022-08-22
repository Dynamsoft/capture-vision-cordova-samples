import { Rect } from "./BasicStructures";
export interface TorchButton {
    location: Rect;
    visible: boolean;
    torchOnImage: string;
    torchOffImage: string;
}
