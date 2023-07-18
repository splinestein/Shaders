// Published to: https://www.shadertoy.com/view/csjfRm

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float minIntensity = 1.5;
    float maxIntensity = 5.5;
    float combinedIntensity = 150.0;
    float waveZoom = 4.0;
    float waveStretch = 1.5;
    
    vec2 uv = (fragCoord * 2.0 - iResolution.xy) / iResolution.y;
    vec2 uv0 = waveZoom * uv;
    
    vec3 finalCol = vec3(0.0);
    
    uv0.y += waveStretch * sin(uv0.x - (iTime * 0.75));
    
    float lineIntensity = minIntensity + (maxIntensity * abs(mod(uv.x + iTime, 2.0) - 1.0));
    float glowWidth = abs(lineIntensity / (combinedIntensity * uv0.y));

    finalCol += vec3(glowWidth * (1.0 + sin(iTime * 0.33)),
                  glowWidth * (1.0 - sin(iTime * 0.33)),
                  glowWidth * (1.0 - cos(iTime * 0.33)));
    
	fragColor = vec4(finalCol, 1.0);
}
