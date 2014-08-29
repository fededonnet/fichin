#include "fichin/fAnimation.hpp"

////////////////////////////////////////////////////////////////////////////////

fAnimation::fAnimation(const std::string &name, const std::initializer_list<int> &frames, float fps, bool loop)
{
	_name = name;
	_frames.insert(_frames.end(), frames.begin(), frames.end());
	_frameDuration = 1.0/fps;
	_loop = loop;
}
