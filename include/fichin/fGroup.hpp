#ifndef __FGROUP_HPP__
#define __FGROUP_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <fichin/fTypedGroup.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Un actor especial que puede contener a otros
///			actores.
/// 		
/// \see fActor, fScene
///
////////////////////////////////////////////////////////////
class fGroup: public fTypedGroup<fActor>
{
public:
	
	
private:
	fActor *recycle();
};
#endif // __FGROUP_HPP__

////////////////////////////////////////////////////////////
/// \class fGroup
///
/// fGroup es un actor que puede contener a otros actores.
/// Facilita la realizaci�n de operaciones sobre todo un
/// conjunto de actores como actualizaci�n, dibujado,
/// cambio de visibilidad, etc.
/// 
/// Los grupos pueden ser agregados a una escena como si se
/// tratase de otro actor m�s. Adem�s, otros actores pueden
/// ser agregados al grupo, logrando de esta manera componer
/// un �rbol jer�rquico de actores. Los actores agregados a
/// un grupo se actualizar�n autom�ticamente cada vez que
/// �ste lo haga, lo mismo ocurre con el dibujado.
///
/// Ejemplo de uso:
/// \code
/// 
/// class MyScene: public fScene
/// {
/// 	void init()
///		{
///			// crea un grupo
///			fGroup *g = new fGroup;
///			// crea y agrega 10 sprites al grupo
///			for(int i=0; i<10; i++)
///			{
///				g->add(new fSprite());
///			}
///			// agrega el grupo a la escena
///			add(g);
///		}
/// };
/// 
/// \endcode
///
/// \see fActor, fScene
///
////////////////////////////////////////////////////////////
