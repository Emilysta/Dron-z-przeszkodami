#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: drone
	./drone

drone: obj obj/main.o obj/Cuboid.o obj/lacze_do_gnuplota.o\
		   obj/GeometricFigure.o obj/Prism.o obj/SceneObject.o\
		   obj/Drone.o obj/stage_service.o obj/Scene.o\
		   obj/Obstacle.o obj/Factory.o

	g++ -Wall -pedantic -std=c++0x -o drone obj/main.o\
                        obj/Cuboid.o obj/lacze_do_gnuplota.o obj/Scene.o\
						obj/GeometricFigure.o obj/Prism.o obj/Drone.o\
						obj/stage_service.o obj/Obstacle.o obj/SceneObject.o\
						obj/Factory.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Scene.hh inc/stage_service.hh\
           inc/lacze_do_gnuplota.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hh inc/GeometricFigure.hh
	g++ -c ${CXXFLAGS} -o obj/Cuboid.o src/Cuboid.cpp

obj/GeometricFigure.o: src/GeometricFigure.cpp inc/GeometricFigure.hh inc/Vector3D.hh\
						inc/Point3D.hh inc/Matrix3x3.hh
	g++ -c ${CXXFLAGS} -o obj/GeometricFigure.o src/GeometricFigure.cpp
	
obj/Prism.o: src/Prism.cpp inc/Prism.hh inc/Cuboid.hh
	g++ -c ${CXXFLAGS} -o obj/Prism.o src/Prism.cpp

obj/Drone.o: src/Drone.cpp inc/Drone.hh inc/Prism.hh inc/lacze_do_gnuplota.hh\
			inc/SceneObject.hh
	g++ -c ${CXXFLAGS} -o obj/Drone.o src/Drone.cpp

obj/Obstacle.o: src/Obstacle.cpp inc/Obstacle.hh inc/Cuboid.hh\
				inc/SceneObject.hh
	g++ -c ${CXXFLAGS} -o obj/Obstacle.o src/Obstacle.cpp

obj/SceneObject.o: src/SceneObject.cpp inc/SceneObject.hh inc/Vector3D.hh
	g++ -c ${CXXFLAGS} -o obj/SceneObject.o src/SceneObject.cpp

obj/Scene.o: src/Scene.cpp inc/Scene.hh inc/Drone.hh inc/Obstacle.hh
	g++ -c ${CXXFLAGS} -o obj/Scene.o src/Scene.cpp

obj/stage_service.o: src/stage_service.cpp inc/stage_service.hh inc/Vector3D.hh inc/lacze_do_gnuplota.hh
	g++ -c ${CXXFLAGS} -o obj/stage_service.o src/stage_service.cpp

obj/Factory.o: src/Factory.cpp inc/Factory.hh inc/SceneObject.hh 
	g++ -c ${CXXFLAGS} -o obj/Factory.o src/Factory.cpp

clean:
	rm -f obj/*.o Drone
	rm *.dat
	rmdir obj

