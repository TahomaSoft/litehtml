#include "html.h"
#include "el_td.h"


litehtml::el_td::el_td( litehtml::document* doc ) : element(doc)
{

}

litehtml::el_td::~el_td()
{

}

void litehtml::el_td::parse_styles(bool is_reparse)
{
	const wchar_t* str = get_attr(L"width");
	if(str)
	{
		m_style.add_property(L"width", str, 0, false);
	}
	str = get_attr(L"background");
	if(str)
	{
		std::wstring url = L"url('";
		url += str;
		url += L"')";
		m_style.add_property(L"background-image", url.c_str(), 0, false);
	}
	str = get_attr(L"align");
	if(str)
	{
		m_style.add_property(L"text-align", str, 0, false);
	}

	str = get_attr(L"valign");
	if(str)
	{
		m_style.add_property(L"vertical-align", str, 0, false);
	}

	element::parse_styles(is_reparse);
}
