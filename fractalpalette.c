// Published to: https://www.shadertoy.com/view/DdjBzW

vec3 pal( in float t, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
{
    // Function from iq's palette shader.
    return a + b * cos(6.28318 * ( c * t + d));
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = (fragCoord * 2. - iResolution.xy) / iResolution.y;
    vec2 uv0 = uv;
    vec3 finalCol = vec3(0.0);
    
    uv = fract(uv * 3.0)-0.5;
    
    for (float i = 0.0; i < 3.0; i++) {
        float d = length(uv);

        vec3 col = pal( length(uv0) + (iTime * .5), vec3(0.5), vec3(0.5), vec3(1.0), vec3(0.0,0.33,0.67) );
        vec3 col2 = pal( length(uv0) + (iTime * .5), vec3(0.3), vec3(0.2), vec3(1.0), vec3(0.0,0.5,0.67) );

        d = sin(d * 10. + iTime);

        finalCol += col * d;
        finalCol -= col2 * d;
    }
    
    fragColor = vec4(finalCol, 1.0);
}
