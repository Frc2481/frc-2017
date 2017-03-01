import matplotlib.pyplot as plt
from ast import literal_eval as make_tuple
import math

def dist(x1, y1, x2, y2):
    return math.sqrt(pow(x1-x2,2) + pow(y1-y2,2))

centers = []
lu = []
lb = []
ru = []
rb = []

f = open("tempPath.txt", 'r')
for line in f:
    if line.startswith("DEBUG"):
        continue
    points = line[:-1].split(" ")
    centers.append(make_tuple(points[0]))
    lu.append(make_tuple(points[1]))
    ru.append(make_tuple(points[2]))
    lb.append(make_tuple(points[3]))
    rb.append(make_tuple(points[4]))
cx = [p[0] for p in centers]
cy = [p[1] for p in centers]
lux = [p[0] for p in lu]
luy = [p[1] for p in lu]
lbx = [p[0] for p in lb]
lby = [p[1] for p in lb]
rux = [p[0] for p in ru]
ruy = [p[1] for p in ru]
rbx = [p[0] for p in rb]
rby = [p[1] for p in rb]

#Run sanity check
for i in range(len(lu)):
    dist1 = dist(lux[i], luy[i], rux[i], ruy[i])
    dist2 = dist(lux[i], luy[i], lbx[i], lby[i])
    dist3 = dist(rbx[i], rby[i], rux[i], ruy[i])
    dist4 = dist(rbx[i], rby[i], lbx[i], lby[i])
    if not (dist1 < 23.02 and dist1 > 22.98):
        print "Dist1 too large!", dist1
    if not (dist2 < 23.02 and dist2 > 22.98):
        print "Dist2 too large!", dist2
    if not (dist3 < 23.02 and dist3 > 22.98):
        print "Dist3 too large!", dist3
    if not (dist4 < 23.02 and dist4 > 22.98):
        print "Dist4 too large!", dist4

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(cx, cy, 'black', linewidth=2)
ax.plot(lux, luy, 'red')
ax.plot(lbx, lby, 'green')
ax.plot(rux, ruy, 'blue')
ax.plot(rbx, rby, 'orange')
ax.set_xlim(xmin=0.0, xmax=130.0)
ax.set_ylim(ymin=0.0, ymax=130.0)
plt.show()
