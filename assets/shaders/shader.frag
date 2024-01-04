
uniform vec4 u_Color;
uniform sampler2D u_Texture;

varying vec2 v_TexCoord;

void main()                                          
{                                                   
	vec4 tex = u_Color;
	tex = texture2D(u_Texture, v_TexCoord);
	gl_FragColor = tex;                              
}                  