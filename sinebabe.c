// Published to: https://www.shadertoy.com/view/DdSBDz

/*

Copyright splinestein, 2023.

I am the sole copyright owner of this Work.
You cannot host, display, distribute or share this Work in any form,
including physical and digital. You cannot use this Work in any
commercial or non-commercial product, website or project. You cannot
sell this Work and you cannot mint an NFTs of it.

*/

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{    
    float minIntensity = 1.5;
    float maxIntensity = 2.5;
    float combinedIntensity = 20000.0;
    float waveZoom = 2.3;
    float waveStretch = 0.23;
    float startTime = 12444. + iTime;
    
    vec2 uv = (fragCoord * 2.0 - iResolution.xy) / iResolution.y;
    vec2 uv0 = waveZoom * uv;
    
    vec3 finalCol = vec3(0.0);
    
    for (float i = 2.0; i < 22.; i++) {
        uv0.y += waveStretch * (sin(uv0.x - ((startTime * sin(i)) - 0.36)) + cos(uv0.y - ((startTime * cos(i)) + 0.53)));
      
        float lineIntensity = minIntensity + (maxIntensity * abs(mod(uv.x + startTime, 2.0) - 1.0));
        float glowWidth = abs(lineIntensity / (combinedIntensity * uv0.y));

        finalCol += vec3(glowWidth * (i + sin(startTime)),
                      glowWidth * (1. - sin(startTime)),
                      glowWidth * (6. - cos(startTime)));
    }
    
	fragColor = vec4(finalCol, 1.0);
}
