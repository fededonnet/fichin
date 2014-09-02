#ifndef __FGROUP_HPP__
#define __FGROUP_HPP__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <fichin/fActor.hpp>

////////////////////////////////////////////////////////////
/// \brief 	Un actor especial que puede contener a otros
///			actores.
/// 		
/// \see fActor, fScene
///
////////////////////////////////////////////////////////////
class fGroup: public fActor
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Actualiza grupo de actores
	///
	/// Es llamada automáticamente por la escena para actualizar
	/// al grupo.
	///
	/// \param dt Tiempo transcurrido desde la última actualización
	///
	////////////////////////////////////////////////////////////
	virtual void update(float dt);
	
	////////////////////////////////////////////////////////////
	/// \brief Dibuja el grupo de actores
	///
	/// Dibuja al grupo en la ventana target con los estados states.
	/// Es llamada automáticamente por la escena. 
	///
	/// \param target La ventana en donde se debe dibujar al actor
	/// \param states Estados para el dibujado del actor en la ventana
	///
	/// \see sf::RenderTarget, sf::RenderStates
	///
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget &w, sf::RenderStates s) const;
	
	////////////////////////////////////////////////////////////
	/// \brief Agrega un actor al grupo
	///
	/// \param actor El actor que será agregado al grupo
	///
	/// \see fActor
	///
	////////////////////////////////////////////////////////////
	void add(fActor *actor);
	
	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	////////////////////////////////////////////////////////////
	virtual ~fGroup();
	
private:
	std::vector<fActor *> _members;	///< Los actores que componen el grupo
};
#endif // __FGROUP_HPP__

////////////////////////////////////////////////////////////
/// \class fGroup
///
/// fGroup es un actor que puede contener a otros actores.
/// Facilita la realización de operaciones sobre todo un
/// conjunto de actores como actualización, dibujado,
/// cambio de visibilidad, etc.
/// 
/// Los grupos pueden ser agregados a una escena como si se
/// tratase de otro actor más. Además, otros actores pueden
/// ser agregados al grupo, logrando de esta manera componer
/// un árbol jerárquico de actores. Los actores agregados a
/// un grupo se actualizarán automáticamente cada vez que
/// éste lo haga, lo mismo ocurre con el dibujado.
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
