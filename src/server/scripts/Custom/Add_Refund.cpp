#include "ScriptPCH.h"
#include "Language.h"
#include "Chat.h"

class refundvendor : public CreatureScript
{
    public:

        refundvendor()
            : CreatureScript("refundvendor")
        {
        }
		
	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface/icons/Spell_Shadow_Shadowform:25|tRefund: Donor Weapons", GOSSIP_SENDER_MAIN, 2000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface/icons/INV_Axe_113:25|tRefund: Rings/Trinkets/Amulets", GOSSIP_SENDER_MAIN, 3000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface/icons/INV_Axe_113:25|tRefund: Rapier Donor Weapon and Shield", GOSSIP_SENDER_MAIN, 4000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "|TInterface/icons/INV_Axe_113:25|tRefund: Abomination Misc", GOSSIP_SENDER_MAIN, 5000);
			
			 pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());

            return true;
        }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{
		case 2000:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: One-Handed Weapons", GOSSIP_SENDER_MAIN, 2001);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Two-Handed Weapons", GOSSIP_SENDER_MAIN, 2002);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Staves", GOSSIP_SENDER_MAIN, 2003);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Ranged", GOSSIP_SENDER_MAIN, 2004);
			//pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Off-Hand Weapons", GOSSIP_SENDER_MAIN, 2005);
			//pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Main-Hand Weapons", GOSSIP_SENDER_MAIN, 2006);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
		case 2001:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Sword - 8 Dp", GOSSIP_SENDER_MAIN, 2101);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Axe - 8 Dp", GOSSIP_SENDER_MAIN, 2102);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Melee Dagger - 8 Dp", GOSSIP_SENDER_MAIN, 2103);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Spell Dagger - 8 Dp", GOSSIP_SENDER_MAIN, 2104);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Mace  - 8 Dp", GOSSIP_SENDER_MAIN, 2105);

			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
		case  2101:
			if (pPlayer->HasItemCount(200169, 1))
			{
				pPlayer->DestroyItemCount(200169, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200169);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case  2102:
			if (pPlayer->HasItemCount(200170, 1))
			{
				pPlayer->DestroyItemCount(200170, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200170);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case  2103:
			if (pPlayer->HasItemCount(200180, 1))
			{
				pPlayer->DestroyItemCount(200180, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200180);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case   2104:
			if (pPlayer->HasItemCount(200228, 1))
			{
				pPlayer->DestroyItemCount(200228, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200228);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case  2105://mace
			if (pPlayer->HasItemCount(200171, 1))
			{
				pPlayer->DestroyItemCount(200171, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200171);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

			//end one hannd

		case 2002:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Dual Axe  - 14 Dp", GOSSIP_SENDER_MAIN, 2208);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Dual Sword  - 14 Dp", GOSSIP_SENDER_MAIN, 2209);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Dual Mace  - 14 Dp", GOSSIP_SENDER_MAIN, 2210);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Polearm  - 14 Dp", GOSSIP_SENDER_MAIN, 2214);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
		case  2208: //dual axe
			if (pPlayer->HasItemCount(200178, 1))
			{
				pPlayer->DestroyItemCount(200178, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200178);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case  2209:  //dual sword
			if (pPlayer->HasItemCount(200176, 1))
			{
				pPlayer->DestroyItemCount(200176, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200176);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case  2210://dual mace
			if (pPlayer->HasItemCount(200177, 1))
			{
				pPlayer->DestroyItemCount(200177, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200177);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case  2214://polearm
			if (pPlayer->HasItemCount(200230, 1))
			{
				pPlayer->DestroyItemCount(200230, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200230);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			//end two hand

		case 2003:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Spell Staff  - 14 Dp", GOSSIP_SENDER_MAIN, 2312);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Feral Staff  - 14 Dp", GOSSIP_SENDER_MAIN, 2313);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
		case 2312://spell staff
			if (pPlayer->HasItemCount(200179, 1))
			{
				pPlayer->DestroyItemCount(200179, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200179);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case 2313://feral staff
			if (pPlayer->HasItemCount(200229, 1))
			{
				pPlayer->DestroyItemCount(200229, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200229);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 14 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			//end staves
		case 2004:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Bow  - 8 Dp", GOSSIP_SENDER_MAIN, 2405);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Gun  - 8 Dp", GOSSIP_SENDER_MAIN, 2406);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Final Achievement Wand  - 6 Dp", GOSSIP_SENDER_MAIN, 2407);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
		case 2405: //bow
			if (pPlayer->HasItemCount(200172, 1))
			{
				pPlayer->DestroyItemCount(200172, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200172);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case 2406://gun
			if (pPlayer->HasItemCount(200173, 1))
			{
				pPlayer->DestroyItemCount(200173, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200173);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 8 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;

		case 2407://wabd
			if (pPlayer->HasItemCount(200181, 1))
			{
				pPlayer->DestroyItemCount(200181, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200181);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 6 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Account in Site for detail !!");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			//end of range
		case 3000: // ringand trinket
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Melee Ring 5 DP", GOSSIP_SENDER_MAIN, 3001);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Melee Trinket 5 DP", GOSSIP_SENDER_MAIN, 3002);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Melee Amulet/Neck 5 DP", GOSSIP_SENDER_MAIN, 3003);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Caster Ring 5 DP", GOSSIP_SENDER_MAIN, 3004);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Caster Trinket 5 DP", GOSSIP_SENDER_MAIN, 3005);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Donor Caster Amulet/Neck 5 DP", GOSSIP_SENDER_MAIN, 3006);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;

		case 3001:
			if (pPlayer->HasItemCount(200161, 1))
			{
				pPlayer->DestroyItemCount(200161, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200161);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case 3002:
			if (pPlayer->HasItemCount(200162, 1))
			{
				pPlayer->DestroyItemCount(200162, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200162);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case 3003:
			if (pPlayer->HasItemCount(200163, 1))
			{
				pPlayer->DestroyItemCount(200163, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200163);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case 3004:
			if (pPlayer->HasItemCount(200216, 1))
			{
				pPlayer->DestroyItemCount(200216, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200216);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case 3005:
			if (pPlayer->HasItemCount(200217, 1))
			{
				pPlayer->DestroyItemCount(200217, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200217);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		case 3006:
			if (pPlayer->HasItemCount(200215, 1))
			{
				pPlayer->DestroyItemCount(200215, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(200215);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 5 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4000:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier One-Handed Weapons", GOSSIP_SENDER_MAIN, 4001);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Two-Handed Weapons", GOSSIP_SENDER_MAIN, 4002);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Staves", GOSSIP_SENDER_MAIN, 4003);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Ranged", GOSSIP_SENDER_MAIN, 4004);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Shields", GOSSIP_SENDER_MAIN, 4005);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4001:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Sword - 18 Dp", GOSSIP_SENDER_MAIN, 4101);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Axe - 18 Dp", GOSSIP_SENDER_MAIN, 4102);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Melee Dagger - 18 Dp", GOSSIP_SENDER_MAIN, 4103);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Spell Dagger - 18 Dp", GOSSIP_SENDER_MAIN, 4104);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Mace  - 18 Dp", GOSSIP_SENDER_MAIN, 4105);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4101:
			if (pPlayer->HasItemCount(10825, 1))
			{
				pPlayer->DestroyItemCount(10825, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(10825);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 18 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4102: //one hand axe
			if (pPlayer->HasItemCount(5286, 1))
			{
				pPlayer->DestroyItemCount(5286, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(5286);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 18 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4103: //melee dagger
			if (pPlayer->HasItemCount(10619, 1))
			{
				pPlayer->DestroyItemCount(10619, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(10619);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 18 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4104: //spell dagger
			if (pPlayer->HasItemCount(10618, 1))
			{
				pPlayer->DestroyItemCount(10618, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(10618);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 18 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4105: //mace
			if (pPlayer->HasItemCount(2182, 1))
			{
				pPlayer->DestroyItemCount(2182, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(2182);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 18 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			// end for one hand
			
			case 4002:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Two Hand Sword - 24 Dp", GOSSIP_SENDER_MAIN, 4201);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Two Hand Axe - 24 Dp", GOSSIP_SENDER_MAIN, 4202);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Two Hand Mace  - 24 Dp", GOSSIP_SENDER_MAIN, 4203);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Polearm  - 24 Dp", GOSSIP_SENDER_MAIN, 4204);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4201: //mace
			if (pPlayer->HasItemCount(13150, 1))
			{
				pPlayer->DestroyItemCount(13150, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(13150);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
		
			case 4202: 
			if (pPlayer->HasItemCount(22199, 1))
			{
				pPlayer->DestroyItemCount(22199, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(22199);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4203: 
			if (pPlayer->HasItemCount(10685, 1))
			{
				pPlayer->DestroyItemCount(10685, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(10685);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4204: 
			if (pPlayer->HasItemCount(12403, 1))
			{
				pPlayer->DestroyItemCount(12403, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(12403);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			// end for two hand
			
			case 4003:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Spell Staff - 24 Dp", GOSSIP_SENDER_MAIN, 4301);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Feral Staff - 24 Dp", GOSSIP_SENDER_MAIN, 4302);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4301: 
			if (pPlayer->HasItemCount(13050, 1))
			{
				pPlayer->DestroyItemCount(13050, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(13050);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4302: 
			if (pPlayer->HasItemCount(14392, 1))
			{
				pPlayer->DestroyItemCount(14392, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(14392);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 24 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4004:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Bow - 17 Dp", GOSSIP_SENDER_MAIN, 4401);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Wand - 17 Dp", GOSSIP_SENDER_MAIN, 4402);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Gun - 17 Dp", GOSSIP_SENDER_MAIN, 4403);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4401: 
			if (pPlayer->HasItemCount(14118, 1))
			{
				pPlayer->DestroyItemCount(14118, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(14118);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 17 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4402: 
			if (pPlayer->HasItemCount(20350, 1))
			{
				pPlayer->DestroyItemCount(20350, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(20350);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 17 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4403: 
			if (pPlayer->HasItemCount(13924, 1))
			{
				pPlayer->DestroyItemCount(13924, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(13924);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 17 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4005:
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Tank Shield - 15 Dp", GOSSIP_SENDER_MAIN, 4501);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: Rapier Silence Galdiator Spel Shield - 15 Dp", GOSSIP_SENDER_MAIN, 4502);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Refund: [Main Menu]", GOSSIP_SENDER_MAIN, 9999);
			pPlayer->PlayerTalkClass->SendGossipMenu(85006, pCreature->GetGUID());
			return true;
			break;
			
			case 4501: 
			if (pPlayer->HasItemCount(210908, 1))
			{
				pPlayer->DestroyItemCount(210908, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(210908);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 15 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
			case 4502: 
			if (pPlayer->HasItemCount(210903, 1))
			{
				pPlayer->DestroyItemCount(210903, 1, true);
				ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(210903);
				LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 15 WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PQuery("INSERT INTO web_db.refund (account_id, character_name, donation_item_name) VALUES ('%u', '%s', '%s')", pPlayer->GetSession()->GetAccountId(), pPlayer->GetName(), itemTemplate->Name1.c_str());
				pPlayer->GetSession()->SendNotification("Success. Your donor item has been removed and your points has been refunded.Check your Dp for detail !!");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			else {
				pPlayer->GetSession()->SendNotification("Failed. Make sure you have the desired item");
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}
			break;
			
		case 9999:
			pPlayer->PlayerTalkClass->ClearMenus();
			OnGossipHello(pPlayer, pCreature);
			break;
		}
		  return true;
	}			
					
    
};

void AddSC_refundvendor()
{
    new refundvendor();
}