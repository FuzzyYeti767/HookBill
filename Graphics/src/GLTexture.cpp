/*
 * Rudy Castan Jinseok Son
 * CS200
 * Fall 2022
 */

#include <iostream>

#include "GLTexture.h"
#include "glCheck.h"
#include <stb_image.h>

GLTexture::~GLTexture() noexcept
{
    delete_texture();
}

void GLTexture::delete_texture() noexcept
{
    // invoke glDeleteTextures
    glDeleteTextures(1, &texture_handle);
    texture_handle = 0; // so we don't accidentally double it
    width = 0;
    height = 0;
}


GLTexture::GLTexture(GLTexture&& other) noexcept
{
    texture_handle = other.texture_handle;
    width = other.width;
    height = other.height;
    filtering = other.filtering;
    wrapping = other.wrapping;

    other.texture_handle = 0;
}

GLTexture& GLTexture::operator =(GLTexture&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    else
    {
        texture_handle = other.texture_handle;
        width = other.width;
        height = other.height;
        filtering = other.filtering;
        wrapping = other.wrapping;

        other.texture_handle = 0;

        return *this;
    }
}

bool GLTexture::LoadFromFileImage(const std::filesystem::path& image_filepath, bool flip_vertical) noexcept
{
    // invoke stbi_set_flip_vertically_on_load()
    stbi_set_flip_vertically_on_load(flip_vertical);


    //  set the desired channel count to 4
    const int desired_channel = 4;

    // invoke stbi_load() to get the RGBA data, width, height

    //RGBA* texture = (RGBA*)(stbi_load(image_filepath.string().c_str(), &widths, &heights, &comps, desired_channel));

    RGBA* texture = reinterpret_cast<RGBA*>(stbi_load(image_filepath.string().c_str(), &widths, &heights, &comps, desired_channel));

    if (texture == nullptr)
    {
        std::cout << "Doesn't load the image\n";
        return false;
    }

    // invoke LoadFromMemory()
    if (!LoadFromMemory(widths, heights, texture))
    {
        return false;
    }

    // invoke stbi_image_free()
    stbi_image_free((void*)texture);

    // return if successful
    return true;
}

bool GLTexture::LoadFromMemory(int image_width, int image_height, const RGBA* colors) noexcept
{
    // delete current texture
    // copy and save image width
    // copy and save image height
    delete_texture();

    width = image_width;
    height = image_height;

    // Create 1 texture
    // Create immutable storage of widthxheight RGBA8 GPU memory with only one texture level
    // Send `colors` data to GPU memory
    constexpr GLsizei TEXTURE_COUNT = 1;
    glCheck(glCreateTextures(GL_TEXTURE_2D, TEXTURE_COUNT, &texture_handle));

    constexpr GLsizei ONE_TEXTURE_LEVEL = 1;
    glCheck(glTextureStorage2D(texture_handle, ONE_TEXTURE_LEVEL, GL_RGBA8, width, height));

    constexpr GLint   FIRST_LEVEL = 0;
    constexpr GLsizei OFFSET_X = 0, OFFSET_Y = 0;
    glCheck(glTextureSubImage2D(texture_handle, FIRST_LEVEL, OFFSET_X, OFFSET_Y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, colors));

    // Set Filtering to nearest pixel
    SetFiltering(filtering);
    // Set Wrapping to the repeat pattern
    SetWrapping(wrapping[static_cast<unsigned int>(Coordinate::S)], Coordinate::S);
    SetWrapping(wrapping[static_cast<unsigned int>(Coordinate::T)], Coordinate::T);
    // return if successful

    return true;
}

void GLTexture::SetFiltering(Filtering how_to_filter) noexcept
{
    if (texture_handle == 0)
        return;

    filtering = how_to_filter;

    glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering));
    glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering));
}

void GLTexture::SetWrapping(Wrapping how_to_wrap, Coordinate coord) noexcept
{
    if (texture_handle == 0)
    {
        return;
    }


    unsigned int repeat_way;

    if (coord == Coordinate::T)
    {
        repeat_way = GL_TEXTURE_WRAP_T;
    }
    else
    {
        repeat_way = GL_TEXTURE_WRAP_S;
    }


    if (coord == Coordinate::Both)
    {
        glCheck(glTextureParameteri(texture_handle, GL_TEXTURE_WRAP_T, how_to_wrap));
        glCheck(glTextureParameteri(texture_handle, GL_TEXTURE_WRAP_S, how_to_wrap));

        return;
    }

    glCheck(glTextureParameteri(texture_handle, repeat_way, how_to_wrap));
}

void GLTexture::UseForSlot(unsigned texture_unit) const noexcept
{
    glCheck(glBindTextureUnit(texture_unit, texture_handle));
}