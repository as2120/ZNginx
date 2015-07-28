﻿////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
    m_vertexBuffer = 0;
    m_indexBuffer = 0;
    m_Texture1 = 0;
    m_Texture2 = 0;
    m_Texture3 = 0;
    m_model = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(ID3D10Device* device, char* modelFilename, WCHAR* textureFilename1, WCHAR* textureFilename2,
                            WCHAR* textureFilename3)
{
    bool result;


    // Load in the model data.
    result = LoadModel(modelFilename);
    if(!result)
    {
        return false;
    }

    // Initialize the vertex and index buffer that hold the geometry for the triangle.
    result = InitializeBuffers(device);
    if(!result)
    {
        return false;
    }

    // Load the textures for this model.
    result = LoadTextures(device, textureFilename1, textureFilename2, textureFilename3);
    if(!result)
    {
        return false;
    }

    return true;
}


void ModelClass::Shutdown()
{
    // Release the model textures.
    ReleaseTextures();

    // Release the vertex and index buffers.
    ShutdownBuffers();

    // Release the model data.
    ReleaseModel();

    return;
}


void ModelClass::Render(ID3D10Device* device)
{
    // Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
    RenderBuffers(device);

    return;
}


int ModelClass::GetIndexCount()
{
    return m_indexCount;
}


bool ModelClass::InitializeBuffers(ID3D10Device* device)
{
    VertexType* vertices;
    unsigned long* indices;
    D3D10_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
    D3D10_SUBRESOURCE_DATA vertexData, indexData;
    HRESULT result;
    int i;


    // Create the vertex array.
    vertices = new VertexType[m_vertexCount];
    if(!vertices)
    {
        return false;
    }

    // Create the index array.
    indices = new unsigned long[m_indexCount];
    if(!indices)
    {
        return false;
    }

    // Load the vertex array and index array with data.
    for(i=0; i<m_vertexCount; i++)
    {
        vertices[i].position = D3DXVECTOR3(m_model[i].x, m_model[i].y, m_model[i].z);
        vertices[i].texture = D3DXVECTOR2(m_model[i].tu, m_model[i].tv);
        indices[i] = i;
    }

    // Set up the description of the vertex buffer.
    vertexBufferDesc.Usage = D3D10_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
    vertexBufferDesc.BindFlags = D3D10_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;

    // Give the subresource structure a pointer to the vertex data.
    vertexData.pSysMem = vertices;

    // Now finally create the vertex buffer.
    result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
    if(FAILED(result))
    {
        return false;
    }

    // Set up the description of the index buffer.
    indexBufferDesc.Usage = D3D10_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
    indexBufferDesc.BindFlags = D3D10_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;

    // Give the subresource structure a pointer to the index data.
    indexData.pSysMem = indices;

    // Create the index buffer.
    result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
    if(FAILED(result))
    {
        return false;
    }

    // Release the arrays now that the vertex and index buffers have been created and loaded.
    delete [] vertices;
    vertices = 0;

    delete [] indices;
    indices = 0;

    return true;
}


void ModelClass::ShutdownBuffers()
{
    // Release the index buffer.
    if(m_indexBuffer)
    {
        m_indexBuffer->Release();
        m_indexBuffer = 0;
    }

    // Release the vertex buffer.
    if(m_vertexBuffer)
    {
        m_vertexBuffer->Release();
        m_vertexBuffer = 0;
    }

    return;
}


void ModelClass::RenderBuffers(ID3D10Device* device)
{
    unsigned int stride;
    unsigned int offset;


    // Set vertex buffer stride and offset.
    stride = sizeof(VertexType);
    offset = 0;

    // Set the vertex buffer to active in the input assembler so it can be rendered.
    device->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

    // Set the index buffer to active in the input assembler so it can be rendered.
    device->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

    // Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
    device->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    return;
}


bool ModelClass::LoadTextures(ID3D10Device* device, WCHAR* textureFilename1, WCHAR* textureFilename2, WCHAR* textureFilename3)
{
    bool result;


    // Create the texture object.
    m_Texture1 = new TextureClass;
    if(!m_Texture1)
    {
        return false;
    }

    // Initialize the texture object.
    result = m_Texture1->Initialize(device, textureFilename1);
    if(!result)
    {
        return false;
    }

    // Create the texture object.
    m_Texture2 = new TextureClass;
    if(!m_Texture2)
    {
        return false;
    }

    // Initialize the texture object.
    result = m_Texture2->Initialize(device, textureFilename2);
    if(!result)
    {
        return false;
    }

    // Create the texture object.
    m_Texture3 = new TextureClass;
    if(!m_Texture3)
    {
        return false;
    }

    // Initialize the texture object.
    result = m_Texture3->Initialize(device, textureFilename3);
    if(!result)
    {
        return false;
    }

    return true;
}


void ModelClass::ReleaseTextures()
{
    // Release the texture objects.
    if(m_Texture1)
    {
        m_Texture1->Shutdown();
        delete m_Texture1;
        m_Texture1 = 0;
    }

    if(m_Texture2)
    {
        m_Texture2->Shutdown();
        delete m_Texture2;
        m_Texture2 = 0;
    }

    if(m_Texture3)
    {
        m_Texture3->Shutdown();
        delete m_Texture3;
        m_Texture3 = 0;
    }

    return;
}


ID3D10ShaderResourceView* ModelClass::GetTexture1()
{
    return m_Texture1->GetTexture();
}


ID3D10ShaderResourceView* ModelClass::GetTexture2()
{
    return m_Texture2->GetTexture();
}


ID3D10ShaderResourceView* ModelClass::GetTexture3()
{
    return m_Texture3->GetTexture();
}


bool ModelClass::LoadModel(char* filename)
{
    ifstream fin;
    char input;
    int i;


    // Open the model file.  If it could not open the file then exit.
    fin.open(filename);
    if(fin.fail())
    {
        return false;
    }

    // Read up to the value of vertex count.
    fin.get(input);
    while(input != ':')
    {
        fin.get(input);
    }

    // Read in the vertex count.
    fin >> m_vertexCount;

    // Set the number of indices to be the same as the vertex count.
    m_indexCount = m_vertexCount;

    // Create the model using the vertex count that was read in.
    m_model = new ModelType[m_vertexCount];
    if(!m_model)
    {
        return false;
    }

    // Read up to the beginning of the data.
    fin.get(input);
    while(input != ':')
    {
        fin.get(input);
    }
    fin.get(input);
    fin.get(input);

    // Read in the vertex data.
    for(i=0; i<m_vertexCount; i++)
    {
        fin >> m_model[i].x >> m_model[i].y >> m_model[i].z;
        fin >> m_model[i].tu >> m_model[i].tv;
        fin >> m_model[i].nx >> m_model[i].ny >> m_model[i].nz;
    }

    // Close the model file.
    fin.close();

    return true;
}


void ModelClass::ReleaseModel()
{
    if(m_model)
    {
        delete [] m_model;
        m_model = 0;
    }

    return;
}
