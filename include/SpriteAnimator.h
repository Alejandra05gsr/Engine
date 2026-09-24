#pragma once
#include "raylib.h"

namespace kai {

    class SpriteAnimator {
    private:
        Rectangle frameRec = { 0.0f, 0.0f, 0.0f, 0.0f };
        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 8;   
        int totalFrames = 3;    
        Texture2D texture;

    public:
        SpriteAnimator() = default;

        void init(Texture2D tex, int numFrames = 3, int speed = 8)
        {
            texture = tex;
            totalFrames = numFrames;
            framesSpeed = speed;
            currentFrame = 0;
            framesCounter = 0;

            float frameWidth = (float)texture.width / (float)totalFrames;
            float frameHeight = (float)texture.height;

            frameRec = { 0.0f, 0.0f, frameWidth, frameHeight };
        }

        void update()
        {
            framesCounter++;

            if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame >= totalFrames) currentFrame = 0;

                frameRec.x = (float)currentFrame * frameRec.width;
            }
        }

        void draw(Vector2 position)
        {
            if (texture.id == 0) return;

            Vector2 pos = { position.x - frameRec.width / 2.0f, position.y - frameRec.height / 2.0f };
            DrawTextureRec(texture, frameRec, pos, WHITE);
        }

        float getFrameWidth() const { return frameRec.width; }
        float getFrameHeight() const { return frameRec.height; }
    };

}