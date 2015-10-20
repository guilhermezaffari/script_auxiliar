%% ========================================================================
% Initialisation
%==========================================================================

close all;
clear all;
clc;
%%
dr = fopen('dead_reckoning.txt');
A = fscanf(dr,'%f');
fclose(dr);

em = fopen('experience_map.txt'); 
B = fscanf(em, '%f');
fclose(em);

gt = fopen('ground_truth.txt');
C = fscanf(gt, '%f');
fclose(gt);

A=A';B=B';C=C';
x=size(A); x=x(2)
j=1;

for i=1:3:x
    A1(j,1)=A(i);
    A1(j,2)=A(i+1);
    A1(j,3)=A(i+2);
    B1(j,1)=B(i);
    B1(j,2)=B(i+1);
    B1(j,3)=B(i+2);
    C1(j,1)=C(i);
    C1(j,2)=C(i+1);
    C1(j,3)=C(i+2);
    
    j=j+1;
end


w=size(A1);w=w(1);
i=1:w;
x=min(A1(i,1));
y=min(A1(i,2));
z=min(A1(i,3));
x1=min(B1(i,1));
y1=min(B1(i,2));
z1=min(B1(i,3));
x2=min(C1(i,1));
y2=min(C1(i,2));
z2=min(C1(i,3));

for i=1:w
    A1(i,1)=-x+A1(i,1);
    A1(i,2)=-y+A1(i,2);
    A1(i,3)=-z+A1(i,3);
    
    B1(i,1)=-x1+B1(i,1);
    B1(i,2)=-y1+B1(i,2);
    B1(i,3)=-z1+B1(i,3);
    
    C1(i,1)=-x2+C1(i,1);
    C1(i,2)=-y2+C1(i,2);
    C1(i,3)=-z2+C1(i,3);
end
i=1:w;
figure;
plot3(A1(i,1),A1(i,2),A1(i,3),'r',B1(i,1),B1(i,2),B1(i,3),'b',C1(i,1),C1(i,2),C1(i,3),'g');
legend('Dead Reckoning','Experience Map','Ground Truth');
xlabel('x');
zlabel('z');
ylabel('y');
set(gca, 'ZDir', 'reverse');
set(gca, 'XDir', 'reverse');

grid

