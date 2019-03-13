#pragma once
#include<vector>
#include<iostream>

using std::vector;
struct Pose {
	int x, y;
	Pose (int x_pose, int y_pose): x(x_pose), y(y_pose) {
	}

  Pose(){}

  inline bool operator==(Pose a) {
   if (a.x==x && a.y== y)
      return true;
   else
      return false;
  }
};

enum class BarrierType {
  FREE_SPACE,
  ROCK,
  WATER,
  BARRIER,
  LAVA,   
  TELEPORT
};


struct Cell {
  Pose pose;
  BarrierType barrier_type;
  Cell() {}
  Cell(Pose p, BarrierType bt) {
    pose = p;
    barrier_type = bt;
  }
};

struct Sequence {
	vector<Pose> seq;
};

inline std::ostream& operator<<(std::ostream& os, const Pose& m)
{
    return os << "x: " <<  m.x << ", y: " << m.y; 
} 

inline std::ostream& operator << (std::ostream& os, const BarrierType& obj)
{
   os << static_cast<std::underlying_type<BarrierType>::type>(obj);
   return os;
}

inline std::ostream& operator<<(std::ostream& os, const Cell& c)
{
    return os << "pose: " <<  c.pose << ", barrier_type: " << c.barrier_type; 
}