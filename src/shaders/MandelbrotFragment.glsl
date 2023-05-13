R"(
#version 410

out vec4 FragColor;
in vec4 gl_FragCoord;

uniform double width;
uniform double height;
uniform int maxIterations;
uniform int randomX;
uniform int randomY;
uniform double scaleFactor;

double divider = sqrt(maxIterations);
double left = -2.125, right = 0.75, top = 1.125, bottom = -1.125;

#define cx_mul(a, b) vec2(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x)
#define cx_abs(a) length(a)

vec2 cx_z_squared_plus_c(vec2 z, vec2 c)
{
    return cx_mul(z, z) + c;
}
void zoomMandelbrot()
{
    double dx = right - left ,dy = top - bottom;

    double newCenterX = left + ( randomX * dx / width);
    double newCenterY = bottom + ( randomY * dy / height );

    double newDeltaX = abs( dx * scaleFactor);
    double newdDeltaY = abs( dy * scaleFactor);


    left = newCenterX - ( newDeltaX / 2.0 );
    right = newCenterX + ( newDeltaX / 2.0 );
    bottom = newCenterY - ( newdDeltaY / 2.0 );
    top = newCenterY + ( newdDeltaY / 2.0 );
}
vec3 computeMandelbrot()
{

    // Convert current pixel point to the coordinates on complex plane
    vec2 c = vec2(left + (gl_FragCoord.x * (right - left) / width) , top + (gl_FragCoord.y * (bottom - top) / height));
    vec2 z = vec2(0.0,0.0);
    int i = 0;
    float smooth1 = 0.0,smooth2 = 0.0, smooth3 = 0.0;

    while(cx_abs(z) < 2.0 && i < maxIterations)
    {
        z = cx_z_squared_plus_c(z,c);
        smooth1 += exp(-1.0 * cx_abs(z));
        ++i;
    }
    smooth2 = sin(smooth1) * smooth1;
    smooth3 = cos(smooth1) * smooth1;
    if(i != maxIterations)
    {
        return vec3(smooth3/divider,smooth2/divider,smooth1/divider);
    }
    else
    {
        return vec3(0.0,0.01,0.0);
    }
}
void main()
{
    zoomMandelbrot();
    FragColor  = vec4(computeMandelbrot(),1.0f);
}
)"