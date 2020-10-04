# MiniRT

![Screenshot](/bmp_rendered/arare1_0.bmp)

![Screenshot](/bmp_rendered/ice_cream.bmp)

![Screenshot](/bmp_rendered/snowman.bmp)

![Screenshot](/bmp_rendered/house_inside_0.bmp)

![Screenshot](/bmp_rendered/plane_mix.bmp)

Takes as a first argument a scene description file with the .rt
extension.
If second argument id --save (of -s) it saves bmp image for the first camera of the scene
<br/>
Each type of element can be separated by one or more line break(s).
Each type of information from an element can be separated by one or more
space(s).<br/>
Each type of element can be set in any order in the file. <br/>
Elements which are defined by a capital letter can only be declared once in the scene.<br/>
Each element first’s information is the type identifier (composed by one or two character(s)), followed by all specific information for each object in a strict order such as:
<br/>
<p><b>∗ Resolution:</b>
R 1920 1080 <br/>
 identifier: R <br/>
 x render size <br/>
 y render size <br/></p>

<p><b>∗ Ambient lightning:</b>
A 0.2 255,255,255 <br/>
identifier: A<br/>
ambient lighting ratio in range [0.0, 1.0]: 0.2 <br/>
R,G,B colors in range [0-255]: 255,255,255 <br/></p>

<p><b>∗ Camera:</b>
c -50.0,0,20 0,0,1 70<br/>
identifier: c<br/>
 x,y,z coordinates of the view point: 0.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 FOV : Horizontal field of view in degrees in range [0, 180]<br/>

For sepia filter put "sepia" at the end the Camera description:<br/>
c -50.0,0,20 0,0,1 70 sepia<br/>
</br>
For mini-antialiasing put "aa" at the end the Camera description:<br/>
c -50.0,0,20 0,0,1 70 aa<br/>
for both put "sepia+aa" at the end the Camera description:<br/>
c -50.0,0,20 0,0,1 70 sepia+aa<br/></p>

<p><b>∗ Light:</b>
l -40.0,50.0,0.0 0.6 10,0,255<br/>
 identifier: l<br/>
 x,y,z coordinates of the light point: 0.0,0.0,20.6<br/>
 the light brightness ratio in range [0.0,1.0]: 0.6 · R,G,B colors in range [0-255]: 10, 0, 255<br/></p>

<p>* Parallel light</b>
l -40.0,50.0,0.0 0.6 10,0,255 0,0,1<br/>
 identifier: l<br/>
 x,y,z coordinates of the light point: 0.0,0.0,20.6<br/>
 the light brightness ratio in range [0.0,1.0]: 0.6 · R,G,B colors in range [0-255]: 10,0,255<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/></p>

<p><b>∗ Sphere:</b>
sp 0.0,0.0,20.6 12.6 10,0,255<br/>
 identifier: sp<br/>
 x,y,z coordinates of the sphere center: 0.0,0.0,20.6<br/>
 the sphere diameter: 12.6<br/>
 R,G,B colors in range [0-255]: 10,0,255<br/></p>

<p>* Plane:</b>
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225<br/>
 identifier: pl<br/>
 x,y,z coordinates: 0.0,0.0,-10.0<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 R,G,B colors in range [0-255]: 0,0,255<br/></p>

<p><b>∗ Square:</b>
sq 0.0,0.0,20.6 1.0,0.0,0.0 12.6 255,0,255<br/>
 identifier: sq<br/>
 x,y,z coordinates of the square center: 0.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 side size: 12.6<br/>
 R,G,B colors in range [0-255]: 255,0,255<br/></p>

<p><b>∗ Cylinder:</b>
cy 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42<br/>
 identifier: cy<br/>
 x,y,z coordinates: 50.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 the cylinder diameter: 14.2<br/>
 the cylinder height: 21.42<br/>
 R,G,B colors in range [0,255]: 10,0,255<br/>

To render cylinder with caps put "c" at the end of the description:<br/>
cy 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42 c<br/></p>

<p><b>∗ Triangle:</b>
tr 10.0,20.0,10.0 10.0,10.0,20.0 20.0,10.0,10.0 0,0,255<br/>
 identifier: tr<br/>
 x,y,z coordinates of the first point: 10.0,20.0,10.0<br/>
 x,y,z coordinates of the second point: 10.0,10.0,20.0<br/>
 x,y,z coordinates of the third point: 20.0,10.0,10.0<br/>
 R,G,B colors in range [0,255]: 0,255,255<br/></p>

<p><b>∗ Cone:</b>
co 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42<br/>
 identifier: co<br/>
 x,y,z coordinates of the cone vertex: 50.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 the cone diameter: 14.2<br/>
 the cone height: 21.42<br/>
 R,G,B colors in range [0,255]: 10,0,255<br/></p>

<p><b>∗ Pyramid:</b>
py 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42<br/>
 identifier: py<br/>
 x,y,z coordinates of the pyramid vertex: 50.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 the pyramid's bottom side size: 14.2<br/>
 the pyramid height: 21.42<br/>
 R,G,B colors in range [0,255]: 10,0,255<br/></p>

<p><b>∗ Cube:</b>
cu 0.0,0.0,20.6 1.0,0.0,0.0 12.6 255,0,255<br/>
 identifier: cu<br/>
 x,y,z coordinates of the cube center: 0.0,0.0,20.6<br/>
 3d normalized orientation vector. In range [-1,1] for each x,y,z axis<br/>
 side size: 12.6<br/>
 R,G,B colors in range [0-255]: 255, 0, 255<br/></p>
