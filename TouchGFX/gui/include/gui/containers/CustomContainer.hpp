#ifndef CUSTOMCONTAINER_HPP
#define CUSTOMCONTAINER_HPP

#include <gui_generated/containers/CustomContainerBase.hpp>
#include <touchgfx/Bitmap.hpp>

class CustomContainer : public CustomContainerBase
{
public:
    CustomContainer();
    virtual ~CustomContainer() {}

    virtual void initialize();

    // 🧩 Hàm dùng để cập nhật ảnh tương ứng với giá trị (2, 4, 8, ..., 2048)
    void updateTile(int value);
    void setNumber(uint16_t value);
protected:
};

#endif // CUSTOMCONTAINER_HPP
