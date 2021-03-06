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
        DX11ConstantBuffer(const ConstantBufferDesc& desc);
        ~DX11ConstantBuffer();
        virtual void Bind() override;
        virtual void* GetData() override { return mData; }
        virtual void SetData(void* data) override;
        virtual Uint GetSize() override { return mSize; }

        virtual RendererID GetNativeBuffer() override { return (RendererID)mBuffer; }
        virtual ShaderDomain GetShaderDomain() override { return mShaderDomain; }
        virtual DataUsage GetDataUsage() override { return mDataUsage; }
    private:
        ID3D11Buffer* mBuffer;
        Uint mSize;
        Uint mBindSlot;
        void* mData;
        ShaderDomain mShaderDomain;
        DataUsage mDataUsage;
    };
}
