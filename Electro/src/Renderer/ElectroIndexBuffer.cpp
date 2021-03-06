//                    ELECTRO ENGINE
// Copyright(c) 2021 - Electro Team - All rights reserved
#include "epch.hpp"
#include "ElectroIndexBuffer.hpp"
#include "ElectroRenderer.hpp"
#include "Platform/DX11/DX11IndexBuffer.hpp"

namespace Electro
{
    Ref<IndexBuffer> IndexBuffer::Create(void* indices, Uint count)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::DX11: return Ref<DX11IndexBuffer>::Create(indices, count);
        }

        E_INTERNAL_ASSERT("Unknown RendererAPI!");
        return nullptr;
    }
}
