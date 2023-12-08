
attribute vec4 a_Position;

uniform mat4 u_Projection;     
uniform mat4 u_Model;  

void main()                                          
{              
	gl_Position = u_Projection * u_Model * a_Position;
}