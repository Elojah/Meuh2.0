#ifndef CAMERA_H
# define CAMERA_H


class Camera
{
public:
	Camera(void);
	~Camera(void);
	void	setView(void) const;
	void	rotateAround(float const);
	void	zoom(float const);
protected:
private:
	typedef struct	s_point {
		float		x;
		float		y;
		float		z;
	}				tPoint;

	tPoint			_position;
	tPoint			_viewAt;
};

#endif
