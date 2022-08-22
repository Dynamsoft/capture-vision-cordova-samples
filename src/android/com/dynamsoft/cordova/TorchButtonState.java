package com.dynamsoft.cordova;

import android.graphics.Rect;
import android.graphics.RectF;

//For answering the webView touch event
public class TorchButtonState {
    public RectF locationInCameraView = new RectF();// By px.
    public boolean isVisible;

    public TorchButtonState() {

    }

    public TorchButtonState(float left, float top,float width, float height, boolean isVisible) {
        locationInCameraView.set(left, top, left+width, top+height);
        this.isVisible = isVisible;
    }

    public void setLocationInCameraView(float left, float top, float width, float height) {
        locationInCameraView.set(left, top, left+width, top+height);
    }

    public void setVisible(boolean isVisible) {
        this.isVisible = isVisible;
    }
}
