#pragma once

class UrlHelper
{
public:

    UrlHelper(const std::wstring& url) : m_url(url)
    {
    }

    std::wstring GetUrl()
    {
        auto protocolEnd = m_url.find(':');
        if(protocolEnd == std::wstring::npos)
            throw std::exception("Invalid Url");

        auto urlStart = protocolEnd + 3;
        auto pos = m_url.find('/', urlStart);
        return m_url.substr(urlStart, pos - urlStart);
    }

    std::wstring GetParameter()
    {
        auto protocolEnd = m_url.find(':');
        if(protocolEnd == std::wstring::npos)
            throw std::exception("Invalid Url");

        auto paramStart = m_url.find('/', protocolEnd + 3);
        if(paramStart != std::wstring::npos)
            return m_url.substr(paramStart);
    
        return std::wstring();
    }

    std::wstring m_url;
};

