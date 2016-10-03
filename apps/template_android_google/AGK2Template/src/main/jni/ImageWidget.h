#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "LeafWidget.h"


class ImageWidget : public LeafWidget
{
    public:
        /** Default constructor */
        ImageWidget();
        ImageWidget(const Vector2& position, const Vector2& size);
        ImageWidget(XMLNode* node);
        /** Default destructor */
        virtual ~ImageWidget();
        string GetBackground();
        void SetBackground(const string& file);

    protected:
        virtual void OnBeforeInitialize();
        virtual void OnInitialize();

        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();
        virtual void OnSetBackground();
    private:
        string mBackgroundPath; //!< Member variable "mBackgroundPath"
        int mBackgroundImageId; //!< Member variable "mBackgroundImageId"
        int mBackgroundSpriteId; //!< Member variable "mBackgroundSpriteId"
};

#endif // IMAGEWIDGET_H
