#include <gui/containers/CustomContainer.hpp>
#include <images/BitmapDatabase.hpp>

CustomContainer::CustomContainer()
{

}

void CustomContainer::initialize()
{
    CustomContainerBase::initialize();
    setNumber(0);
}

void CustomContainer::setNumber(uint16_t value)
{
    switch (value)
    {
    case 2:
        tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL2_ID));
        break;
    case 4:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL4_ID));
        break;
    case 8:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL8_ID));
        break;
    case 16:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL16_ID));
        break;
    case 32:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL32_ID));
        break;
    case 64:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL64_ID));
        break;
    case 128:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL128_ID));
        break;
    case 256:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL256_ID));
        break;
    case 512:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL512_ID));
        break;
    case 1024:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL1024_ID));
        break;
    case 2048:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL2048_ID));
        break;
    default:
    	tileImage.setBitmap(touchgfx::Bitmap(BITMAP_CELL0_ID)); // 0 hoặc không hợp lệ
        break;
    }

    tileImage.invalidate(); // Cập nhật lại hình ảnh
}
// 🎯 Hàm cập nhật ảnh theo giá trị
void CustomContainer::updateTile(int value)
{
    using namespace touchgfx;

    // Mặc định là cell0 nếu không khớp
    Bitmap bmp = Bitmap(BITMAP_CELL0_ID);

    switch (value)
    {
    case 2:     bmp = Bitmap(BITMAP_CELL2_ID); break;
    case 4:     bmp = Bitmap(BITMAP_CELL4_ID); break;
    case 8:     bmp = Bitmap(BITMAP_CELL8_ID); break;
    case 16:    bmp = Bitmap(BITMAP_CELL16_ID); break;
    case 32:    bmp = Bitmap(BITMAP_CELL32_ID); break;
    case 64:    bmp = Bitmap(BITMAP_CELL64_ID); break;
    case 128:   bmp = Bitmap(BITMAP_CELL128_ID); break;
    case 256:   bmp = Bitmap(BITMAP_CELL256_ID); break;
    case 512:   bmp = Bitmap(BITMAP_CELL512_ID); break;
    case 1024:  bmp = Bitmap(BITMAP_CELL1024_ID); break;
    case 2048:  bmp = Bitmap(BITMAP_CELL2048_ID); break;
    default:    bmp = Bitmap(BITMAP_CELL0_ID); break;
    }

    tileImage.setBitmap(bmp);
    tileImage.invalidate(); // 👈 Bắt buộc gọi để cập nhật lại giao diện
}
