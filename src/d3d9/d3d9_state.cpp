#include "d3d9_state.h"

#include "d3d9_texture.h"

namespace dxvk {

  // NV-DXVK start: unbound light indices
  D3D9CapturableState::D3D9CapturableState(uint32_t maxEnabledLights) {
  // NV-DXVK end
    for (uint32_t i = 0; i < textures.size(); i++)
      textures[i] = nullptr;

    for (uint32_t i = 0; i < clipPlanes.size(); i++)
      clipPlanes[i] = D3D9ClipPlane();

    for (uint32_t i = 0; i < streamFreq.size(); i++)
      streamFreq[i] = 1;

    // NV-DXVK start: unbound light indices
    enabledLightIndices.resize(maxEnabledLights);
    // NV-DXVK end

    for (uint32_t i = 0; i < enabledLightIndices.size(); i++)
      enabledLightIndices[i] = UINT32_MAX;
  }

  D3D9CapturableState::~D3D9CapturableState() {
    for (uint32_t i = 0; i < textures.size(); i++)
      TextureChangePrivate(textures[i], nullptr);
  }

}