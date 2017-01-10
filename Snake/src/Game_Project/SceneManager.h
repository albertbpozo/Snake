#pragma once
#include "Scene.h"
#include "Assert.h"
#include <typeindex>
#include <unordered_map>

#define SM SceneManager::Instance()

// SceneManager class to store and control the whole game scenes
class SceneManager {
public:
	~SceneManager() { for (auto &scene : m_scenes) delete scene.second; } //destructor de la clase
	inline static SceneManager &Instance() { //singleton
		static SceneManager sceneManager;
		return sceneManager;
	}
	template<class S> void AddScene(void) { // para añadir escenas
		static_assert(std::is_base_of<Scene, S>::value, "Can't add scene that doesn't inherit from IScene");
		m_scenes.emplace(typeid(S), new S); //añade una nueva escena, typeid es posicion y new es "el argumento" 

	}
	template<class S> void SetCurScene(void) { //cambias la escena actual
		static_assert(std::is_base_of<Scene, S>::value, "Can't add scene that doesn't inherit from IScene");
		if (m_curScene != nullptr) //comprueva si hay una escena actualmente
			m_curScene->OnExit(), //sale de la escena actual
			m_curScene->SetState<SceneState::SLEEP>(); //hace que la escena actual este en modo SLEEP
		ASSERT((m_curScene = GetScene<S>()) != nullptr);//se asegura que la escena actual no sea null, es decir que haya alguna escena 
		m_curScene->SetState<SceneState::RUNNING>();//cambia el estado de la escena a RUNNING
		m_curScene->OnEntry(); //entra en la escena
	}
	inline Scene *&GetCurScene(void) { return m_curScene; } //??
private:
	SceneManager() = default;
	SceneManager(const SceneManager &rhs) = delete; //constructor??
	SceneManager &operator=(const SceneManager &rhs) = delete;//??
	template<class S> S *GetScene(void) { //para "pillar una escena" , diferencia entre esta y AddScene--> addscene es añadir escena joan XD --> el get sirve para ver en que escena estas o para versi existe una scena
		auto scene = m_scenes.find(typeid(S)); //asignas a una var la escena
		return (scene != m_scenes.end()) ? dynamic_cast<S*>(scene->second) : nullptr;
		//		si se cumple esta condicion     pasa esto					sino null
		//ai dios ajajajajja, Joan, mientras haya escenas, iterara, si una escena da error, la pone en null o algo asi (google is <3)
	}
private:
	std::unordered_map<std::type_index, Scene*> m_scenes;	// Array of screens
	Scene *m_curScene{ nullptr };							// Pointer to the current scene

};