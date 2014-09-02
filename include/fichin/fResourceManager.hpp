#ifndef __FRESOURCEMANAGER_HPP__
#define __FRESOURCEMANAGER_HPP__
#include <map>
#include <string>
#include <iostream>
using namespace std;

template <class T>
class fResourceCache;

////////////////////////////////////////////////////////////
/// \brief	Clase para gestionar recursos compartidos.
///			Facilita el acceso a recursos como texturas, 
///			sonidos, spritesheets, etc. y evita que existan
///			de manera duplicada en memoria
///
////////////////////////////////////////////////////////////
class fResourceManager{
public:
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conseguir un determinado recurso, el mismo
	///			debe haber sido cargado previamente, de lo contrario
	///			ocurrirá un error
	///
	/// \param resourceName	Nombre con el que se identifica al recurso
	///
	/// \return El recurso buscado
	///
	////////////////////////////////////////////////////////////
	template<class T>
	static const T &get(const std::string &resourceName){
		return fResourceCache<T>::get(resourceName);
	}
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conseguir un determinado recurso, si el mismo
	///			no ha sido cargado aún, trata de crearlo invocando a su
	///			constructor
	///
	/// \param resourceName	Nombre con el que se identifica al recurso
	/// \param args			Parámetros que serán pasados al constructor del objeto
	///
	/// \return El recurso buscado
	///
	////////////////////////////////////////////////////////////
	template <class T, class... Args >
	static const T &load(const std::string &resourceName, Args... args){
		return fResourceCache<T>::load(resourceName, args...);
	}
	
	////////////////////////////////////////////////////////////
	/// \brief 	Permite conseguir un determinado recurso, si el mismo
	///			no ha sido cargado aún, trata de crearlo mediante un
	///			constructor sin parámetros e invocando luego al método
	///			loadFromFile() del mismo
	///
	/// \param resourceName	Nombre con el que se identifica al recurso
	///
	/// \return El recurso buscado
	///
	////////////////////////////////////////////////////////////
	template<class T>
	static const T &loadFromFile(const std::string &resourceName){
		return fResourceCache<T>::loadFromFile(resourceName);
	}
};


////////////////////////////////////////////////////////////
/// \brief	Clase de ayuda para la gestión de recursos. Es
///			utilizada por fResourceManager. Está pensada
///			para uso interno
///
////////////////////////////////////////////////////////////
template<class T>
class fResourceCache{
private:
	static std::map<std::string, T> _resources;
	
	template <class... Args >
	static const T &load(const std::string &resourceName, Args... args){
		typename std::map<std::string, T>::iterator p = _resources.lower_bound(resourceName);
		if(p == _resources.end() || p->first != resourceName){
			cout<<"WARNING: Resource: "+resourceName+" not found. Loading..."<<endl;
			p = _resources.emplace_hint(p, std::piecewise_construct, std::forward_as_tuple(resourceName), std::forward_as_tuple(args...));
		}
		return p->second;
	}
	
	///////////////////////
	/// Devuelve el recurso asociado con el nombre, si no está trata de crearlo usando un constructor por defecto e inicializarlo luego llamando a la funcion f con los parametros args
	//////////////////////
	static const T &loadFromFile(const std::string &fileName){
		typename std::map<std::string, T>::iterator p = _resources.lower_bound(fileName);
		if(p == _resources.end() || p->first != fileName){
			p = _resources.emplace_hint(p, std::piecewise_construct, std::forward_as_tuple(fileName), std::forward_as_tuple());
			if(!p->second.loadFromFile(fileName)){
				cout<<"ERROR: Couldn't load file: "<<fileName<<endl;
			}
		}
		return p->second;
	}
	
	///////////////////////
	/// Devuelve el recurso asociado con el nombre.
	//////////////////////
	static const T &get(const std::string &resourceName){
		typename std::map<std::string, T>::iterator p = _resources.find(resourceName);
		if(p == _resources.end()){
			cout<<"ERROR: Resource "+resourceName+" NOT FOUND."<<endl;
		}
		return p->second;
	}
	
	friend class fResourceManager;
};

template <class T>
typename std::map<std::string, T> fResourceCache<T>::_resources;

#endif // __FRESOURCEMANAGER_HPP__
