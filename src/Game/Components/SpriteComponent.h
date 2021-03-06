//MIT License
//
// Copyright (c) Narongdej Sarnsuwan 2020
// narongdej.dev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef ZYENGINE_SPRITECOMPONENT_H
#define ZYENGINE_SPRITECOMPONENT_H

#include "../Component.h"
#include "../Shader.h"
#include "../Texture2D.h"
#include "TransformComponent.h"

class SpriteComponent : public Component {
public:
    SpriteComponent(std::string shaderName, std::string textureName, glm::vec3 color = glm::vec3(1.0f));
    SpriteComponent(std::string shaderName);

    ~SpriteComponent() override;

    void Initialize() override;
    void Update(float deltaTime) override;
    void Render() override;

    void SetTexture(std::string textureName);

    std::string GetShaderName();
    std::string GetTextureName();

    void ForceTransform(TransformComponent& transform);

private:
    TransformComponent* transform;

    std::string shaderName, textureName;
    unsigned int quadVAO, VBO;
    Texture2D texture;

    glm::mat4 model;
    float rotate;
    glm::vec3 color;

};

#endif //ZYENGINE_SPRITECOMPONENT_H
