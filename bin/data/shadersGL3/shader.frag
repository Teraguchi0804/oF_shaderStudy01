#version 150

// uniform
uniform sampler2DRect tex0;
uniform float contR;
uniform float contG;
uniform float contB;
uniform float brightness;

// varying
in vec2 texCoordVarying;

// output
out vec4 outputColor;

// 
float contrast(float src, float c) {
  src = (src - 0.5) / (1.0 - c * 0.01) + 0.5;
  return src;
}
 
void main() {
    // テクスチャ上の座標を取得する
    vec4 samplerColor = texture(tex0, texCoordVarying);

    // モノクロ化
    // float dest = (samplerColor.r + samplerColor.g + samplerColor.b) / 3.0;

    float r = contrast(samplerColor.r, contR);
    float g = contrast(samplerColor.g, contG);
    float b = contrast(samplerColor.b, contB);
    float a = samplerColor.a;

    vec3 color = vec3(r, g, b);

    vec3 dest = color * brightness; 

    //float dest = color * 1.0;

    //outputColor = texture(tex0, texCoordVarying);
    //vec3 color = vec3(255, 255, 0);
    // outputColor = vec4(vec3(dest), 1.0);
    // outputColor = color * brightness;

    //outputColor = vec4(color * brightness, 1.0);
    outputColor = vec4(vec3(dest), 1.0);
}