#include "graphics/material.hpp"
#include "graphics/shader.hpp"

namespace tec {
	GLenum Material::GetPolygonMode() {
		return this->polygon_mode;
	}

	void Material::SetPolygonMode(const GLenum mode) {
		switch (mode) {
			case GL_POINT:
			case GL_LINE:
			case GL_FILL:
				this->polygon_mode = mode;
				break;
			default:
				this->polygon_mode = GL_FILL;
		}
	}

	std::shared_ptr<Shader> Material::GetShader() {
		return this->shader;
	}

	void Material::SetShader(std::shared_ptr<Shader> s) {
		this->shader = s;
	}

	void Material::SetShader(std::string name) {
		this->shader = ShaderMap::Get(name);
	}

	std::weak_ptr<Material> Material::Create(const std::string name, std::weak_ptr<Shader> shader) {
		auto m = std::make_shared<Material>(shader);
		MaterialMap::Set(name, m);
		return m;
	}
}
