#include "button.h"

Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if(!mTexture.loadFromFile("button.png"))
    {
        std::cout << "Error opening button image.\n";
        exit(1);
    }
    mButton.setTexture(mTexture);

    // temporary until final button is drawn. This will be used with the button.png from lab9 and is needed to rotate the button
    // to give the "pushed" look
    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    mPosition = position;
    mButton.setPosition(mPosition);

    //choose color
    mButtonColor = color;
    mButton.setColor(mButtonColor);
    //set size as a ration of original size
    mButton.setScale(size);

    //Button Text
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);

    mBtnState = state::normal;
}

void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

void Button::update(sf::Event& e, sf::RenderWindow& window)
{

    //Allow window to be expanded without breaking
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

    bool mouseInButton =    worldPos.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && worldPos.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && worldPos.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && worldPos.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mBtnState = state::hovered;
        }
        else
        {
            mBtnState = state::normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::clicked;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::hovered;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    switch(mBtnState)
    {
        case state::normal:
        {
            mButton.setRotation(0);
            mText.setFillColor(mTextNormal);
            break;
        }
        case state::hovered:
        {
            mButton.setRotation(0);
            mText.setFillColor(mTextHover);
            break;
        }
        case state::clicked:
        {
            mButton.setRotation(180);
            mText.setFillColor(mTextHover);
            break;
        }
    }
}
