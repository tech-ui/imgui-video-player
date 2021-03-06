// ogl/tutorial14_render_to_texture/StandardShadingRTT.vertexshader

#ifndef _VertexShaderRTT_H
#define _VertexShaderRTT_H

const std::string VertexShaderCode = "#version 330 core\n"
"\n"
"// Input vertex data, different for all executions of this shader.\n"
"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
"layout(location = 1) in vec2 vertexUV;\n"
"layout(location = 2) in vec3 vertexNormal_modelspace;\n"
"\n"
"// Output data ; will be interpolated for each fragment.\n"
"out vec2 UV;\n"
"out vec3 Position_worldspace;\n"
"out vec3 Normal_cameraspace;\n"
"out vec3 EyeDirection_cameraspace;\n"
"out vec3 LightDirection_cameraspace;\n"
"\n"
"// Values that stay constant for the whole mesh.\n"
"uniform mat4 MVP;\n"
"uniform mat4 V;\n"
"uniform mat4 M;\n"
"uniform vec3 LightPosition_worldspace;\n"
"\n"
"void main(){\n"
"\n"
"	// Output position of the vertex, in clip space : MVP * position\n"
"	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);\n"
"	\n"
"	// Position of the vertex, in worldspace : M * position\n"
"	Position_worldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;\n"
"	\n"
"	// Vector that goes from the vertex to the camera, in camera space.\n"
"	// In camera space, the camera is at the origin (0,0,0).\n"
"	EyeDirection_cameraspace = vec3(0,0,0) - ( V * M * vec4(vertexPosition_modelspace,1)).xyz;\n"
"\n"
"	// Vector that goes from the vertex to the light, in camera space\n"
"	vec3 LightPosition_cameraspace = ( V * vec4(LightPosition_worldspace,1)).xyz;\n"
"	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;\n"
"	\n"
"	// Normal of the the vertex, in camera space\n"
"	Normal_cameraspace = ( V * M * vec4(vertexNormal_modelspace,0)).xyz; // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.\n"
"	\n"
"	// UV of the vertex. No special space for this one.\n"
"	UV = vertexUV;\n"
"}\n";

#endif
