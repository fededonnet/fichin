#include <fichin/fAnimation.hpp>

////////////////////////////////////////////////////////////////////////////////

fAnimation::fAnimation(const std::string &name, const std::initializer_list<int> &frames, float fps, bool loop):
_frameDuration(1.0/fps),
_name(name),
_loop(loop)
{
	_frames.insert(_frames.end(), frames.begin(), frames.end());
}
