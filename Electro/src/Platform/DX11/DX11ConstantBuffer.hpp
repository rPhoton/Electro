//                    ELECTRO ENGINE
// Copyright(c) 2021 - Electro Team - All rights reserved
#pragma once
#include "Renderer/ElectroConstantBuffer.hpp"
#include <d3d11.h>

namespace Electro
{
    class DX11ConstantBuffer : public ConstantBuffer
    {
    public:
        DX11ConstantBuffer(const Ref<Shader>& shader, const String& name, void* data, const Uint size, const Uint bindSlot, ShaderDomain shaderDomain, DataUsage usage);
        ~DX11ConstantBuffer();
        virtual void Bind() override;
        virtual void* GetData() override { return mData; }
        virtual void SetData(void* data) override;
        virtual Uint GetSize() override { return m_Size; }

        virtual RendererID GetNativeBuffer() override { return (RendererID)m_Buffer; }
        virtual ShaderDomain GetShaderDomain() override { return m_ShaderDomain; }
        virtual DataUsage GetDataUsage() override { return mDataUsage; }
    private:
        ID3D11Buffer* m_Buffer;
        Uint m_Size;
        Uint m_BindSlot;
        void* mData;
        ShaderDomain m_ShaderDomain;
        DataUsage mDataUsage;
    };
}