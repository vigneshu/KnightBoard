struct Pose {
	int x, y;
	Pose (int x_pose, int y_pose): x(x_pose), y(y_pose) {
	}

  inline bool operator==(Pose a) {
   if (a.x==x && a.y== y)
      return true;
   else
      return false;
  }
};

struct Cell {
  Pose pose;
  BarrierType barrier_type;
};

struct Sequence {
	vector<Pose> seq;
};

enum class BarrierType {
  FREE_SPACE,
  ROCK,
  WATER,
  BARRIER
  LAVA,   
  TELEPORT
};
