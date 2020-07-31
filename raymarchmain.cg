void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;
	  	vec4 t = texture(iChannel0, uv);
 
    uv -= 11.;
    // Time varying pixel color
    vec3 col = vec3(0);
   
    float d= length(uv) * cos(iTime * 1.1) * sin(iTime *.995);
    col.r = d;
    uv *= 10. + 1. * sin(iTime * 10.);
    uv.x += uv.y * sin(iTime);
    vec2 f_uv = fract(uv) -.05 * col.r;
    d= length(f_uv);
    col.b = d * d * d * d * d;
    
   
    /*
    float d = length(uv) * cos(iTime * sin(iTime));
    col.r = d;
    //uv *= 10. + 1. * sin(iTime * 10.);
    uv.x += uv.y * sin(iTime);
    vec2 f_uv = fract(uv) -.05 * col.r;
    d= length(f_uv);
    col.b = d * d * d * d * d;
    
   */
    // Output to screen
 	// col += t.rgb;
    fragColor = vec4(col,1.0);
}
